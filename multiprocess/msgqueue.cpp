#include "msgqueue.h"
#include <QDebug>
#include "multiprocess/connection.h"

using namespace std;
using namespace app_msg;

static MsgQueue* m_instance;

char in_buffer [MSG_BUFFER_SIZE];
char out_buffer [MSG_BUFFER_SIZE];

MsgQueue::MsgQueue()
{
    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_MESSAGES;
    attr.mq_msgsize = MAX_MSG_SIZE;
    attr.mq_curmsgs = 0;
}

MsgQueue *MsgQueue::getInstance()
{
    if (m_instance == nullptr) {
        m_instance = new MsgQueue();
    }

    return m_instance;
}

void MsgQueue::initMsgQueue()
{
    if ((qd_server = mq_open (SERVER_QUEUE_NAME, O_RDONLY | O_CREAT, QUEUE_PERMISSIONS, &attr)) == -1) {
        perror ("Server: mq_open (server)");
        exit (1);
    }

    std::thread t{ &MsgQueue::listerningMsg, this};
    t.join();
}

void MsgQueue::listerningMsg()
{
    app_msg::Msg msg;
    while (1) {
        if (mq_receive (qd_server, (char*)& msg, MAX_MSG_SIZE, NULL) == -1) {
            perror ("Server: mq_receive");
            exit (1);
        }
        char* client_name = msg.client == CLIENT_1 ? (char*)CLIENT1_QUEUE_NAME : (char*)CLIENT2_QUEUE_NAME;
        qDebug() << "Server: message received : " << msg.msgType << "from" << client_name;
        sendingMsg(msg);
    }
}

void MsgQueue::sendingMsg(Msg msg)
{
    char* client_name = msg.client == CLIENT_1 ? (char*)CLIENT1_QUEUE_NAME : (char*)CLIENT2_QUEUE_NAME;

    if ((qd_client = mq_open (client_name, O_WRONLY)) == 1) {
        perror ("Server: Not able to open client queue");
        return;
    }

    if (mq_send (qd_client, (char *) &msg, sizeof(msg), 0) == -1) {
        perror ("Server: Not able to send message to client");
    }
}

void MsgQueue::closeMesageQueue()
{

}

#include "msgqueue.h"

using namespace std;
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
    while (1) {
        if (mq_receive (qd_server, in_buffer, MSG_BUFFER_SIZE, NULL) == -1) {
            perror ("Server: mq_receive");
            exit (1);
        }

        printf ("Server: message received.\n");

        if ((qd_client = mq_open (in_buffer, O_WRONLY)) == 1) {
            perror ("Server: Not able to open client queue");
            continue;
        }

        sprintf (out_buffer, "%ld", token_number);

        if (mq_send (qd_client, out_buffer, strlen (out_buffer) + 1, 0) == -1) {
            perror ("Server: Not able to send message to client");
            continue;
        }

        printf ("Server: response sent to client.\n");
        token_number++;
    }
}

void MsgQueue::sendingMsg()
{

}

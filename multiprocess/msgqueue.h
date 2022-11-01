#ifndef MSGQUEUE_H
#define MSGQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <thread>
#include <chrono>

#define SERVER_QUEUE_NAME   "/sp-example-server"
#define QUEUE_PERMISSIONS 0660
#define MAX_MESSAGES 10
#define MAX_MSG_SIZE 256
#define MSG_BUFFER_SIZE MAX_MSG_SIZE + 10

class MsgQueue
{
private:
    MsgQueue();

public:
    static MsgQueue* getInstance();

public:
    void initMsgQueue();
    void listerningMsg();
    void sendingMsg();

private:
    mqd_t qd_server, qd_client;   // queue descriptors
    long token_number = 1; // next token to be given to client
    struct mq_attr attr;
};

#endif // MSGQUEUE_H

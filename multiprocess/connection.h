#pragma once

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#define CLIENT1_QUEUE_NAME "/client_1"
#define CLIENT2_QUEUE_NAME "/client_2"
#define SERVER_QUEUE_NAME   "/hai-phan"
#define QUEUE_PERMISSIONS   0660
#define MAX_MESSAGES        10
#define MAX_MSG_SIZE        2048
#define MSG_BUFFER_SIZE     MAX_MSG_SIZE + 10


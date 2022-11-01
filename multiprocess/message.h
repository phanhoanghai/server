#ifndef MESSAGE_H
#define MESSAGE_H

#include "../app1/data/employee.h"

namespace app_msg {
enum MSG_TYPE
{
    UPDATE_DATA = 0,
    RELOAD_DATA
};

enum CLIENT
{
    CLIENT_1 = 0,
    CLIENT_2
};

typedef struct Msg
{
    MSG_TYPE msgType;
    CLIENT client;
    int index;
    int data[5];
} Msg;
}

#endif // MESSAGE_H

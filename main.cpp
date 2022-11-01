#include <iostream>
#include "Controller/datamanager.h"
#include "multiprocess/sharemem.h"
#include "multiprocess/msgqueue.h"

using namespace std;

int main()
{
    DataManager::getInstance()->initDataFromJsonFile();
    ShareMem::getInstance()->initShareMem();
    MsgQueue::getInstance()->initMsgQueue();
    return 0;
}

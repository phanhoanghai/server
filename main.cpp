#include <iostream>
#include "Controller/datamanager.h"
#include "multiprocess/sharemem.h"

using namespace std;

int main()
{
    DataManager::getInstance()->initDataFromJsonFile();
    ShareMem::getInstance()->initShareMem();
//    qDebug("%s", DataManager::getInstance()->getTextData().toStdString().c_str());
    return 0;
}

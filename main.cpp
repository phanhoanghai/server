#include <iostream>
#include "Controller/datamanager.h"

using namespace std;

int main()
{
    DataManager::getInstance()->initDataFromJsonFile();
    qDebug("%s", DataManager::getInstance()->getTextData().toStdString().c_str());
    return 0;
}

#include <iostream>
#include "Controller/datamanager.h"

using namespace std;

int main()
{
    DataManager::getInstance()->initDataFromJsonFile();
    return 0;
}

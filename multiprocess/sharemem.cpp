#include "sharemem.h"
#include "Controller/datamanager.h"
#include <string>

using namespace std;

static ShareMem* m_instance;

ShareMem::ShareMem() {}

ShareMem *ShareMem::getInstance()
{
    if (m_instance != nullptr) {
        m_instance = new ShareMem;
    }
    return m_instance;
}

bool ShareMem::initShareMem()
{
    int shm_fd;
    string data = DataManager::getInstance()->getTextData().toStdString();
//    qDebug("%s", data.c_str());
    const char* message_0 = data.c_str();
    void* ptr;

    shm_fd = shm_open("app_data", O_CREAT | O_RDWR, 0666);

    ftruncate(shm_fd, 4096);
    ptr = mmap(0, 4096, PROT_WRITE, MAP_SHARED, shm_fd, 0);
    strcpy((char*)ptr, message_0);
    return true;
}

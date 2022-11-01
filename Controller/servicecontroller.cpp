#include "servicecontroller.h"

static ServiceController* m_instance;

ServiceController::ServiceController()
{

}

ServiceController *ServiceController::getInstance()
{
    if (m_instance == nullptr) {
        m_instance = new ServiceController();
    }

    return m_instance;
}

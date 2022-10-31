#include "datamanager.h"

DataManager::DataManager() :
    m_data(""), m_jsonData("")
{

}

DataManager::~DataManager()
{

}


DataManager* DataManager::getInstance() {
    if (m_instance == nullptr) {
        m_instance = new DataManager;
    }
    return m_instance;
}

bool DataManager::initDefaultRawData()
{
    m_data = "[{\"index\":0,\"name\":\"Torres Figueroa\",\"assem\":1,\"cplus\":2,\"js\":4,\"qml\":2,\"openGL\":1},"
             "{\"index\":1,\"name\":\"Noemi Cross\",\"assem\":0,\"cplus\":4,\"js\":2,\"qml\":5,\"openGL\":4},"
             "{\"index\":2,\"name\":\"Ashlee Lowe\",\"assem\":2,\"cplus\":3,\"js\":1,\"qml\":2,\"openGL\":4},"
             "{\"index\":3,\"name\":\"Shepard Cohen\",\"assem\":0,\"cplus\":0,\"js\":5,\"qml\":3,\"openGL\":0},"
             "{\"index\":4,\"name\":\"Rush Meadows\",\"assem\":2,\"cplus\":0,\"js\":2,\"qml\":5,\"openGL\":0},"
             "{\"index\":5,\"name\":\"Leta Hinton\",\"assem\":2,\"cplus\":4,\"js\":4,\"qml\":5,\"openGL\":2},"
             "{\"index\":6,\"name\":\"Lawanda Brown\",\"assem\":1,\"cplus\":3,\"js\":2,\"qml\":4,\"openGL\":1},"
             "{\"index\":7,\"name\":\"King Valenzuela\",\"assem\":4,\"cplus\":3,\"js\":4,\"qml\":0,\"openGL\":5},"
             "{\"index\":8,\"name\":\"Kathie Farmer\",\"assem\":1,\"cplus\":1,\"js\":5,\"qml\":1,\"openGL\":5},"
             "{\"index\":9,\"name\":\"Evelyn Malone\",\"assem\":1,\"cplus\":5,\"js\":0,\"qml\":3,\"openGL\":0},"
             "{\"index\":10,\"name\":\"Melton Burgess\",\"assem\":4,\"cplus\":1,\"js\":1,\"qml\":2,\"openGL\":5},"
             "{\"index\":11,\"name\":\"Meyer Boyle\",\"assem\":3,\"cplus\":2,\"js\":0,\"qml\":0,\"openGL\":1},"
             "{\"index\":12,\"name\":\"Celeste England\",\"assem\":1,\"cplus\":5,\"js\":5,\"qml\":2,\"openGL\":4},"
             "{\"index\":13,\"name\":\"Lynch Fernandez\",\"assem\":0,\"cplus\":4,\"js\":2,\"qml\":1,\"openGL\":2},"
             "{\"index\":14,\"name\":\"Cassandra Fuller\",\"assem\":2,\"cplus\":0,\"js\":2,\"qml\":5,\"openGL\":5},"
             "{\"index\":15,\"name\":\"Roman Molina\",\"assem\":4,\"cplus\":1,\"js\":0,\"qml\":2,\"openGL\":5},"
             "{\"index\":16,\"name\":\"Terrell Schneider\",\"assem\":1,\"cplus\":2,\"js\":0,\"qml\":4,\"openGL\":4}]\";";

    if (m_data.length() > 0) return true;
    return false;
}

bool DataManager::convertRawToJsonData(QString &data)
{

}

bool DataManager::updateData()
{

}

QJsonObject DataManager::getJsonData()
{

}

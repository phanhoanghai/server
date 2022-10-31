#include "datamanager.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <string>

using namespace std;

const string datas[7] = {"index", "name", "assem", "cplus", "js", "qml", "openGL"};
static DataManager* m_instance;

DataManager::DataManager() {}

DataManager::~DataManager() {}


DataManager* DataManager::getInstance() {
    if (m_instance == nullptr) {
        m_instance = new DataManager;
    }
    return m_instance;
}

bool DataManager::initDataFromJsonFile()
{
    QFile json_file("/home/hai/processApp/server/data/employee.json");
    QString json_string;

    if (json_file.open(QIODevice::ReadOnly | QIODevice::Text)){
        json_string = json_file.readAll();
        json_file.close();
    } else {
        qDebug()<< "file not found";
    }

    auto json_doc = QJsonDocument::fromJson(json_string.toUtf8());

    QJsonArray jArr = json_doc.array();
    QJsonValue val;

    for (auto jsonObj : jArr) {
        QJsonObject obj;

        for (int i = 0; i < 7; i++) {
            val = jsonObj.toObject().value(datas[i].c_str());
            obj.insert(datas[i].c_str(), jsonObj.toObject().value(datas[i].c_str()));
        }
        m_jsonData.append(obj);
    }

    // init text data
    m_textData = jsonToText(m_jsonData);
    return true;
}

bool DataManager::updateData()
{

}

QString DataManager::jsonToText(QJsonArray &data)
{
    QJsonDocument doc;
    doc.setArray(data);
    QString stringdata(doc.toJson());
    return stringdata;
}

QJsonArray DataManager::getJsonData()
{
    return m_jsonData;
}

QString DataManager::getTextData()
{
    return m_textData;
}



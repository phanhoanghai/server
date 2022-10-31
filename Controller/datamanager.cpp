#include "datamanager.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

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
    QFile json_file("/home/avn/app1/server/data/employee.json");
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

        val = jsonObj.toObject().value("index");
        obj.insert("index", jsonObj.toObject().value("index"));

        val = jsonObj.toObject().value("name");
        obj.insert("name", jsonObj.toObject().value("name"));

        val = jsonObj.toObject().value("assem");
        obj.insert("assem", jsonObj.toObject().value("assem"));

        val = jsonObj.toObject().value("cplus");
        obj.insert("cplus", jsonObj.toObject().value("cplus"));

        val = jsonObj.toObject().value("js");
        obj.insert("js", jsonObj.toObject().value("js"));

        val = jsonObj.toObject().value("qml");
        obj.insert("qml", jsonObj.toObject().value("qml"));

        val = jsonObj.toObject().value("openGL");
        obj.insert("openGL", jsonObj.toObject().value("openGL"));

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



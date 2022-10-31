#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QString>
#include <QJsonArray>

class DataManager
{
private:
    DataManager();
    ~DataManager();

public:
    static DataManager* getInstance();

public:
    bool initDataFromJsonFile();
    bool updateData();
    QJsonArray getJsonData();
    QString getTextData();

private:
    QString jsonToText(QJsonArray& data);

private:
    QJsonArray m_jsonData;
    QString m_textData;
};

#endif // DATAMANAGER_H

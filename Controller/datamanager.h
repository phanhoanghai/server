#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QJsonObject>
#include <QString>

class DataManager
{
private:
    DataManager();
    ~DataManager();

public:
    static DataManager* getInstance();

private:
    static DataManager* m_instance;

public:
    bool initDefaultRawData();
    bool convertRawToJsonData(QString& data);
    bool updateData();
    QJsonObject getJsonData();

private:
    QString m_data;
    QString m_jsonData;
};

#endif // DATAMANAGER_H

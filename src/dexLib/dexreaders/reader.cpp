#include "reader.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

QJsonArray Reader::readJsonArray(const QString &filePath)
{
    // add is array check
    QByteArray byteArray = readFile(filePath);

    if (!byteArray.isEmpty())
    {
        QJsonDocument doc = QJsonDocument::fromJson(byteArray);
        if (!doc.isNull())
        {
            return doc.array();
        }
    }

    // warning
    return QJsonArray();
}

QJsonObject Reader::readJsonObject(const QString &filePath)
{
    // add is object check
    QByteArray byteArray = readFile(filePath);

    if (!byteArray.isEmpty())
    {
        QJsonDocument doc = QJsonDocument::fromJson(byteArray);
        if (!doc.isNull())
        {
            return doc.object();
        }
    }

    // warning
    return QJsonObject();
}

bool Reader::writeJson(const QString &filePath, const QJsonObject &object)
{
    if (object.isEmpty())
    {
        qInfo() << "No object to write.";
        return true;
    }
    QJsonDocument doc(object);

    QFile file(filePath);

    if (!file.open(QFile::WriteOnly))
    {
        qWarning() << "Error opening" << filePath <<  "for writing";
        return false;
    }
    if (file.write(doc.toJson()) < 0)
    {
        qWarning() << "Error writing to" << filePath;
        file.close();
        return false;
    }

    file.close();
    return true;
}

Reader::Reader()
{

}

QByteArray Reader::readFile(const QString &filePath)
{
    QFile file(filePath);

    if (!file.exists())
    {
        // warning
        return QByteArray();
    }

    if (!file.open(QFile::ReadOnly))
    {
        // warning
        return QByteArray();
    }

    QByteArray byteArray = file.readAll();
    file.close();

    return byteArray;
}

#include "reader.h"

#include <QFile>
#include <QJsonDocument>

QJsonArray Reader::readJson(const QString &filePath)
{
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

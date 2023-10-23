#pragma once

#include <QJsonArray>

class Reader
{
public:
    static QJsonArray readJsonArray(const QString &filePath);
    static QJsonObject readJsonObject(const QString &filePath);
    static bool writeJson(const QString &filePath, const QJsonObject &object);

private:
    Reader();

    static QByteArray readFile(const QString &filePath);
};

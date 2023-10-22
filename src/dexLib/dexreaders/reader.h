#pragma once

#include <QJsonArray>

class Reader
{
public:
    static QJsonArray readJson(const QString &filePath);

private:
    Reader();

    static QByteArray readFile(const QString &filePath);


};

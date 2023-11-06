#pragma once

// Qt headers
#include <QObject>
#include <QDir>

// library headers
#include "dexlib_export.h"
#include "reader.h"

template <typename T>
class DEXLIB_EXPORT Dex
{

public:
    explicit Dex(const QString &filepath);
    Dex(const Dex &other) = delete;
    ~Dex();

    const bool read();

    const QSharedPointer<T> entry(const QString &key);
    const QStringList list();

protected:
    QMap<QString, QSharedPointer<T>> m_dex;
    virtual QSharedPointer<T> create(const QJsonObject &object) = 0;
    virtual const QString key(const QJsonObject &object) = 0;

private:
    const QString m_filepath;

};

template<typename T>
Dex<T>::Dex(const QString &filepath):
    m_dex(),
    m_filepath(filepath)
{

}

template<typename T>
Dex<T>::~Dex()
{

}

template<typename T>
const bool Dex<T>::read()
{
    m_dex.clear();
    QJsonArray array = Reader::readJsonArray(m_filepath);

    for (const QJsonValue &value : array)
    {
        if (value.isObject())
        {
            QJsonObject obj = value.toObject();
            m_dex.insert(key(obj), create(obj));
        }
        else
        {
            qWarning() << "No json object.";
        }
    }

    return true;
}

template<typename T>
const QSharedPointer<T> Dex<T>::entry(const QString &key)
{
    return m_dex.value(key);
}

template<typename T>
const QStringList Dex<T>::list()
{
    return m_dex.keys();
}

#include "dex.h"

#include "reader.h"

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
    //const QString filename = m_dir.absoluteFilePath("types.json");            // (Windows ex.) App executable path

    QJsonArray array = Reader::readJsonArray(m_filepath);

    for (const QJsonValue &value : array)
    {
        if (value.isObject())
        {
            QObject obj = value.toObject();
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

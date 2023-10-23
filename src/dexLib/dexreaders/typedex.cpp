#include "typedex.h"

#include <QJsonObject>
#include <QDir>

#include "reader.h"
#include "type.h"

TypeDex::TypeDex(const QDir &dir,
                 QObject *parent):
    QObject(parent),
    m_dir(dir),
    m_types()
{

}

TypeDex::~TypeDex()
{

}

bool TypeDex::read()
{
    m_types.clear();
    const QString filename = m_dir.absoluteFilePath("types.json");            // (Windows ex.) App executable path

    QJsonArray array = Reader::readJsonArray(filename);

    for (const QJsonValue &value : array)
    {
        if (value.isObject())
        {
            m_types << create(value.toObject());
        }
        else
        {
            qWarning() << "No json object";
        }
    }

    return true;
}

QSharedPointer<Type> TypeDex::create(const QJsonObject &object)
{
    const QString type = object.value("type").toString();
    const QStringList effective = object.value("effective").toVariant().toStringList();
    const QStringList ineffective = object.value("ineffective").toVariant().toStringList();
    const QStringList noEffect = object.value("noEffect").toVariant().toStringList();

    return QSharedPointer<Type>(new Type(Info::stringToType(type),
                                         Info::stringListToTypes(effective),
                                         Info::stringListToTypes(ineffective),
                                         Info::stringListToTypes(noEffect)
                                         ));
}

#include "typedex.h"

#include <QJsonObject>

#include "type.h"

TypeDex::TypeDex(const QDir &dir):
    Dex<Type>(dir.absoluteFilePath("types.json"))
{

}

TypeDex::~TypeDex()
{

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

const QString TypeDex::key(const QJsonObject &object)
{
    return object.value("type").toString();
}

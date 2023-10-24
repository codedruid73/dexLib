#include "abilitydex.h"

#include <QJsonObject>

#include "ability.h"

AbilityDex::AbilityDex(const QDir &dir):
    Dex<Ability>(dir.absoluteFilePath("abilities.json"))

{

}

AbilityDex::~AbilityDex()
{

}

QSharedPointer<Ability> AbilityDex::create(const QJsonObject &object)
{
    const QString name = object.value("name").toString();
    const QString description = object.value("description").toString();

    return QSharedPointer<Ability>(new Ability(name,
                                               description));
}

const QString AbilityDex::key(const QJsonObject &object)
{
    return object.value("name").toString();
}

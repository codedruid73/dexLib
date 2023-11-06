#include "pokemondex.h"

#include <QJsonObject>

#include "pokemoninfo.h"

PokemonDex::PokemonDex(const QDir &dir):
    Dex<PokemonInfo>(dir.absoluteFilePath("pokedex.json"))
{

}

PokemonDex::~PokemonDex()
{

}

QSharedPointer<PokemonInfo> PokemonDex::create(const QJsonObject &object)
{
    const ushort id        = object.value("id").toInt(); // future: change to include forms
    const ushort dexNumber = object.value("id").toInt();
    const QString name     = object.value("name").toObject().value("english").toString();

    const QStringList types = object.value("type").toVariant().toStringList();
    Info::Type primaryType = Info::stringToType(types.at(0));
    Info::Type secondaryType = Info::Type::NONE;
    if (types.size() > 1)
    {
        secondaryType = Info::stringToType(types.at(1));
    }

    // basestats
    ushort hp, att, def, satt, sdef, spe;
    if (object.contains("base"))
    {
        QJsonObject stats = object.value("base").toObject();
        hp = stats.value("HP").toInt();
        att = stats.value("Attack").toInt();
        def = stats.value("Defense").toInt();
        satt = stats.value("Sp. Attack").toInt();
        sdef = stats.value("Sp. Defense").toInt();
        spe = stats.value("Speed").toInt();
    }
    else
    {
        hp = att = def = satt = sdef = spe = 1;
    }
    const BaseStats baseStats(hp, att, def, satt, sdef, spe);

    const QString species = object.value("species").toString();
    const QString description = object.value("description").toString();

    // ability
    QMap<QString, bool> abilities;

    const QJsonArray ab = object.value("ability").toArray();
    for(const QJsonValue &v : ab)
    {
        QStringList obj = v.toVariant().toStringList();
        abilities.insert(obj.at(0), obj.at(1) == "True");
    }

    return QSharedPointer<PokemonInfo>(new PokemonInfo(id,
                                                       dexNumber,
                                                       name,
                                                       primaryType,
                                                       secondaryType,
                                                       baseStats,
                                                       species,
                                                       description,
                                                       abilities));

}

const QString PokemonDex::key(const QJsonObject &object)
{
    return object.value("name").toObject().value("english").toString();
}

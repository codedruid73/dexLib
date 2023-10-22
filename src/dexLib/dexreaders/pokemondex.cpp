#include "pokemondex.h"

#include "pokemoninfo.h"
#include "reader.h"

#include <QJsonObject>
#include <QDir>
#include <QCoreApplication>

PokemonDex::PokemonDex(QObject *parent):
    QObject(parent),
    m_dex()
{

}

PokemonDex::~PokemonDex()
{

}

bool PokemonDex::read()
{
    m_dex.clear();
    // TODO: change to resource
    const QString filename = QDir(QCoreApplication::applicationDirPath()).absoluteFilePath("pokedex.json");            // (Windows ex.) App executable path

    QJsonArray array = Reader::readJson(filename);

    for (const QJsonValue &value : array)
    {
        if (value.isObject())
        {
            m_dex << create(value.toObject());
        }
        else
        {
            qWarning() << "No Json object";
        }
    }

    return true;
}

QList<QSharedPointer<PokemonInfo>> PokemonDex::dex() const
{
    return m_dex;
}

const QStringList PokemonDex::names() const
{
    QStringList result;

    for(const QSharedPointer<PokemonInfo> &info : m_dex)
    {
        result << info->name();
    }

    return result;
}

QSharedPointer<PokemonInfo> PokemonDex::create(const QJsonObject &object)
{
    const ushort id        = object.value("id").toInt(); // furture change to include forms
    const ushort dexNumber = object.value("id").toInt();
    const QString name     = object.value("name").toObject().value("english").toString();

    const QStringList types = object.value("type").toVariant().toStringList();
    TypeInfo::Type primaryType = TypeInfo::toType(types.at(0));
    TypeInfo::Type secondaryType = TypeInfo::Type::NONE;
    if (types.size() > 1)
    {
        secondaryType = TypeInfo::toType(types.at(1));
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

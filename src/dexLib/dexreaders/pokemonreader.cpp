#include "pokemonreader.h"

#include <QJsonObject>

#include "pokemondex.h"
#include "pokemon.h"
#include "reader.h"

QSharedPointer<Pokemon> PokemonReader::read(const QString &filepath)
{
    Q_UNUSED(filepath);

    const QJsonObject object = Reader::readJsonObject(filepath);

    // check how not te reread this every thime!
    PokemonDex dex(QDir("P:/projects/data"));
    dex.read();

    const QString name = object.value("name").toString();
    const QString uuid = object.value("uuid").toString();

    // form;
    const QSharedPointer<PokemonInfo> info = dex.entry(name);
    QSharedPointer<Pokemon> pkm(new Pokemon(info, uuid));

    pkm->setLevel(object.value("level").toInt());
    pkm->setGender(object.value("gender").toString());
    pkm->setShiny(object.value("shiny").toBool());
    pkm->setTeraType(Info::stringToType(object.value("teraType").toString()));
    pkm->setItem(object.value("item").toString());
    pkm->setAbility(object.value("ability").toString());

    QJsonObject stats = object.value("stats").toObject();

    auto lambda = [](const QJsonObject &obj) -> ValueSet {
        ValueSet set(obj.value("hp").toInt(),
                     obj.value("att").toInt(),
                     obj.value("def").toInt(),
                     obj.value("sAtt").toInt(),
                     obj.value("sDef").toInt(),
                     obj.value("speed").toInt());

        return set;
    };

    const ValueSet evs = lambda(stats.value("evs").toObject());
    const ValueSet ivs = lambda(stats.value("ivs").toObject());
    pkm->setEvs(evs);
    pkm->setIvs(ivs);

    pkm->setNature(stats.value("nature").toString());
    pkm->setMoves(object.value("moves").toVariant().toStringList());

    if (pkm->isValid())
    {
        return pkm;
    }
    else
    {
        // Warning
        return QSharedPointer<Pokemon>();
    }
}

bool PokemonReader::write(const QString &filepath,
                          const QSharedPointer<Pokemon> &pkm)
{
    QJsonObject object;

    object.insert("name", pkm->info()->name());
    object.insert("uuid", pkm->uuid());
    // form !
    object.insert("level", pkm->level());
    object.insert("gender", pkm->gender());
    object.insert("shiny", pkm->shiny());
    object.insert("teraType", pkm->teraType());
    object.insert("item", pkm->item());
    object.insert("ability", pkm->ability());
    object.insert("stats", createStats(pkm->evs(), pkm->ivs(), pkm->nature()));


    QJsonArray array;
    for (const QString &str : pkm->moves())
    {
        array << str;
    }
    object.insert("moves", array);

    return Reader::writeJson(filepath, object);
}

PokemonReader::PokemonReader()
{

}

const QJsonObject PokemonReader::createStats(const ValueSet &evs,
                                             const ValueSet &ivs,
                                             const QString  &nature)
{
    QJsonObject stats;

    auto lambda = [](const ValueSet &set) -> QJsonObject {
        QJsonObject obj;
        obj.insert("hp", set.hp());
        obj.insert("att", set.att());
        obj.insert("def", set.def());
        obj.insert("sAtt", set.sAtt());
        obj.insert("sDef", set.sDef());
        obj.insert("speed", set.speed());
        return obj;
    };

    stats.insert("evs", lambda(evs));
    stats.insert("ivs", lambda(ivs));
    stats.insert("nature", nature);

    return stats;
}

#include <QtTest>

#include "item.h"
#include "reader.h"
#include "pokemondex.h"
#include "pokemoninfo.h"
#include "pokemon.h"
#include "pokemonreader.h"

class DexServiceTest : public QObject
{
    Q_OBJECT
public:

    DexServiceTest():
        QObject()
    {}

private Q_SLOTS:
    void test();
    void testPkmReadWrite();
};



void DexServiceTest::test()
{
    // P:\projects\data

    Item item(123, "name1", Item::Type::KeyItems, "some item");

    Item item2(item);

    QCOMPARE(item2.id(), 123);
    QCOMPARE(item2.name(), "name1");
    QCOMPARE(item2.type(), Item::Type::KeyItems);
    QCOMPARE(item2.description(), "some item");

    Item item3(Item(123, "name1", Item::Type::KeyItems, "some item"));

    QCOMPARE(item3.id(), 123);
    QCOMPARE(item3.name(), "name1");
    QCOMPARE(item3.type(), Item::Type::KeyItems);
    QCOMPARE(item3.description(), "some item");

    QSharedPointer<PokemonDex> dex(new PokemonDex(QDir("P:/projects/data")));
    dex->read();

    qDebug() << dex->dex().size();

    for(const auto &pp : dex->dex())
    {
        Q_UNUSED(pp)
        //qDebug() << pp->id() << ":" << pp->name();
        //QTest::qWait(2);
    }

    qDebug() << dex->dex().size();
}

void DexServiceTest::testPkmReadWrite()
{
    QSharedPointer<PokemonDex> dex(new PokemonDex(QDir("P:/projects/data")));
    dex->read();
    QSharedPointer<PokemonInfo> info = dex->info("Gardevoir");

    QSharedPointer<Pokemon> pkm(new Pokemon(info));
    pkm->setLevel(80);
    pkm->setGender("Female");
    pkm->setShiny(false);
    pkm->setTeraType(Info::Type::Psychic);
    pkm->setItem("");
    pkm->setAbility("Synchronize");
    pkm->setIvs(ValueSet(31,20,30,1,2,3));
    pkm->setEvs(ValueSet(80,1,2,228,0,196));
    pkm->setNature("Modest");
    pkm->setMoves({"Trick", "Moonblast", "Psyshock", "Thunderbolt"});

    const QString file = QDir(QCoreApplication::applicationDirPath()).absoluteFilePath("Gardevoir.json");
    const QString file2 = QDir(QCoreApplication::applicationDirPath()).absoluteFilePath("Gardevoir2.json");


    PokemonReader::write(file,pkm);



    QSharedPointer<Pokemon> pkm2 = PokemonReader::read(file);

    qDebug() << pkm2->gender();

    PokemonReader::write(file2,pkm2);

    QSharedPointer<Pokemon> pkm3(new Pokemon(info));


    qDebug() << "pkm1 " << pkm->uuid();
    qDebug() << "pkm2 " << pkm2->uuid();
    qDebug() << "pkm3 " << pkm3->uuid();
}

QTEST_GUILESS_MAIN(DexServiceTest)

#include "tst_dexservice.moc"

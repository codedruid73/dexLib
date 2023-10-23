#include <QtTest>

#include "item.h"
#include "reader.h"
#include "pokemondex.h"

#include "pokemoninfo.h"

class ItemTest : public QObject
{
    Q_OBJECT
public:

    ItemTest():
        QObject()
    {}

private Q_SLOTS:
    void test();
};



void ItemTest::test()
{
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

QTEST_GUILESS_MAIN(ItemTest)

#include "tst_item.moc"

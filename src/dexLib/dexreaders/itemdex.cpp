#include "itemdex.h"

#include <QJsonObject>

#include "item.h"

ItemDex::ItemDex(const QDir &dir):
    Dex<Item>(dir.absoluteFilePath("items.json"))
{

}

QSharedPointer<Item> ItemDex::create(const QJsonObject &object)
{
    const QString name = object.value("name").toString();
    const QString type = object.value("type").toString();
    const QString description = object.value("description").toString();

    return QSharedPointer<Item>(new Item(name,
                                         Item::stringToType(type),
                                         description));
}

const QString ItemDex::key(const QJsonObject &object)
{
    return object.value("name").toString();
}

#include "movedex.h"

#include <QJsonObject>

#include "move.h"

MoveDex::MoveDex(const QDir &dir):
    Dex<Move>(dir.absoluteFilePath("moves.json"))
{

}

MoveDex::~MoveDex()
{

}

QSharedPointer<Move> MoveDex::create(const QJsonObject &object)
{
    const QString name = object.value("name").toString();
    const QString category = object.value("category").toString();
    const QString type = object.value("type").toString();
    const QString description = object.value("description").toString();
    const ushort power = object.value("power").toInt();
    const ushort pp = object.value("pp").toInt();
    const ushort accuracy = object.value("accuracy").toInt();


    return QSharedPointer<Move>(new Move(name,
                                         Move::stringToCategory(category),
                                         Info::stringToType(type),
                                         power,
                                         accuracy,
                                         pp,
                                         description));
}

const QString MoveDex::key(const QJsonObject &object)
{
    return object.value("name").toString();
}

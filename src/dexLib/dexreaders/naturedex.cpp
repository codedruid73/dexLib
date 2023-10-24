#include "naturedex.h"

#include <QJsonObject>

#include "nature.h"

NatureDex::NatureDex(const QDir &dir):
    Dex<Nature>(dir.absoluteFilePath("natures.json"))
{

}

NatureDex::~NatureDex()
{

}

QSharedPointer<Nature> NatureDex::create(const QJsonObject &object)
{
    const QString name = object.value("name").toString();
    const QString summary = object.value("summary").toString();
    const double hp = object.value("hp").toDouble();
    const double att = object.value("att").toDouble();
    const double def = object.value("def").toDouble();
    const double sAtt = object.value("spa").toDouble();
    const double sDef = object.value("spd").toDouble();
    const double speed = object.value("spe").toDouble();

    return QSharedPointer<Nature>(new Nature(Info::stringToNature(name),
                                             hp,
                                             att,
                                             def,
                                             sAtt,
                                             sDef,
                                             speed,
                                             summary));
}

const QString NatureDex::key(const QJsonObject &object)
{
    return object.value("name").toString();
}

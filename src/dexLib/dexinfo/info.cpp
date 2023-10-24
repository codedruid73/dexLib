#include "info.h"

#include <limits>

#include <QStringList>

Info::Info()
{

}

QString Info::typeToString(const Type &type)
{
    switch (type) {
    case Type::Bug:
        return QStringLiteral("Bug");
    case Type::Dark:
        return QStringLiteral("Dark");
    case Type::Dragon:
        return QStringLiteral("Dragon");
    case Type::Electric:
        return QStringLiteral("Electric");
    case Type::Fairy:
        return QStringLiteral("Fairy");
    case Type::Fighting:
        return QStringLiteral("Fighting");
    case Type::Fire:
        return QStringLiteral("Fire");
    case Type::Flying:
        return QStringLiteral("Flying");
    case Type::Ghost:
        return QStringLiteral("Ghost");
    case Type::Grass:
        return QStringLiteral("Grass");
    case Type::Ground:
        return QStringLiteral("Ground");
    case Type::Ice:
        return QStringLiteral("Ice");
    case Type::Normal:
        return QStringLiteral("Normal");
    case Type::Poison:
        return QStringLiteral("Poison");
    case Type::Psychic:
        return QStringLiteral("Psychic");
    case Type::Rock:
        return QStringLiteral("Rock");
    case Type::Steel:
        return QStringLiteral("Steel");
    case Type::Water:
        return QStringLiteral("Water");
    case Type::NONE:
    default:
        return QStringLiteral("NONE");
    }
}

Info::Type Info::stringToType(const QString &type)
{
    if (type == QStringLiteral("Bug"))
        return Type::Bug;
    if (type == QStringLiteral("Dark"))
        return Type::Dark;
    if (type == QStringLiteral("Dragon"))
        return Type::Dragon;
    if (type == QStringLiteral("Electric"))
        return Type::Electric;
    if (type == QStringLiteral("Fairy"))
        return Type::Fairy;
    if (type == QStringLiteral("Fighting"))
        return Type::Fighting;
    if (type == QStringLiteral("Fire"))
        return Type::Fire;
    if (type == QStringLiteral("Flying"))
        return Type::Flying;
    if (type == QStringLiteral("Ghost"))
        return Type::Ghost;
    if (type == QStringLiteral("Grass"))
        return Type::Grass;
    if (type == QStringLiteral("Ground"))
        return Type::Ground;
    if (type == QStringLiteral("Ice"))
        return Type::Ice;
    if (type == QStringLiteral("Normal"))
        return Type::Normal;
    if (type == QStringLiteral("Poison"))
        return Type::Poison;
    if (type == QStringLiteral("Psychic"))
        return Type::Psychic;
    if (type == QStringLiteral("Rock"))
        return Type::Rock;
    if (type == QStringLiteral("Steel"))
        return Type::Steel;
    if (type == QStringLiteral("Water"))
        return Type::Water;

    return Type::NONE;
}

QString Info::natureToString(const Nature &nature)
{
    switch (nature) {
    case Nature::Adamant:
        return QStringLiteral("Adamant");
    case Nature::Bashful:
        return QStringLiteral("Bashful");
    case Nature::Brave:
        return QStringLiteral("Brave");
    case Nature::Bold:
        return QStringLiteral("Bold");
    case Nature::Calm:
        return QStringLiteral("Calm");
    case Nature::Careful:
        return QStringLiteral("Careful");
    case Nature::Docile:
        return QStringLiteral("Docile");
    case Nature::Gentle:
        return QStringLiteral("Gentle");
    case Nature::Hardy:
        return QStringLiteral("Hardy");
    case Nature::Impish:
        return QStringLiteral("Impish");
    case Nature::Jolly:
        return QStringLiteral("Jolly");
    case Nature::Hasty:
        return QStringLiteral("Hasty");
    case Nature::Lax:
        return QStringLiteral("Lax");
    case Nature::Lonely:
        return QStringLiteral("Lonely");
    case Nature::Mild:
        return QStringLiteral("Mild");
    case Nature::Modest:
        return QStringLiteral("Modest");
    case Nature::Naive:
        return QStringLiteral("Naive");
    case Nature::Naughty:
        return QStringLiteral("Naughty");
    case Nature::Quiet:
        return QStringLiteral("Quiet");
    case Nature::Quirky:
        return QStringLiteral("Quirky");
    case Nature::Rash:
        return QStringLiteral("Rash");
    case Nature::Relaxed:
        return QStringLiteral("Relaxed");
    case Nature::Sassy:
        return QStringLiteral("Sassy");
    case Nature::Serious:
        return QStringLiteral("Serious");
    case Nature::Timid:
        return QStringLiteral("Timid");
    case Nature::ERROR:
    default:
        return QStringLiteral("ERROR");
    }
}

Info::Nature Info::stringToNature(const QString &nature)
{
    if (nature == QStringLiteral("Adamant"))
        return Nature::Adamant;
    if (nature == QStringLiteral("Bashful"))
        return Nature::Bashful;
    if (nature == QStringLiteral("Brave"))
        return Nature::Brave;
    if (nature == QStringLiteral("Bold"))
        return Nature::Bold;
    if (nature == QStringLiteral("Calm"))
        return Nature::Calm;
    if (nature == QStringLiteral("Careful"))
        return Nature::Careful;
    if (nature == QStringLiteral("Docile"))
        return Nature::Docile;
    if (nature == QStringLiteral("Gentle"))
        return Nature::Gentle;
    if (nature == QStringLiteral("Hardy"))
        return Nature::Hardy;
    if (nature == QStringLiteral("Hasty"))
        return Nature::Hasty;
    if (nature == QStringLiteral("Impish"))
        return Nature::Impish;
    if (nature == QStringLiteral("Jolly"))
        return Nature::Jolly;
    if (nature == QStringLiteral("Impish"))
        return Nature::Impish;
    if (nature == QStringLiteral("Lax"))
        return Nature::Lax;
    if (nature == QStringLiteral("Lonely"))
        return Nature::Lonely;
    if (nature == QStringLiteral("Mild"))
        return Nature::Mild;
    if (nature == QStringLiteral("Impish"))
        return Nature::Impish;
    if (nature == QStringLiteral("Modest"))
        return Nature::Modest;
    if (nature == QStringLiteral("Naive"))
        return Nature::Naive;
    if (nature == QStringLiteral("Naughty"))
        return Nature::Naughty;
    if (nature == QStringLiteral("Quiet"))
        return Nature::Quiet;
    if (nature == QStringLiteral("Quirky"))
        return Nature::Quirky;
    if (nature == QStringLiteral("Rash"))
        return Nature::Rash;
    if (nature == QStringLiteral("Relaxed"))
        return Nature::Relaxed;
    if (nature == QStringLiteral("Sassy"))
        return Nature::Sassy;
    if (nature == QStringLiteral("Serious"))
        return Nature::Serious;
    if (nature == QStringLiteral("Naughty"))
        return Nature::Naughty;
    if (nature == QStringLiteral("Timid"))
        return Nature::Timid;

    return Nature::ERROR;
}

ushort Info::maxValue(const Value &value)
{
    switch (value) {
    case Value::IV:
        return 31;
    case Value::EV:
        return 252;
    case Value::Base:
    default:
        return std::numeric_limits<ushort>::max();
    }
}

QString Info::displayName(Stats & stats)
{
    switch (stats) {
    case Stats::HP:
        return QStringLiteral("Hit Points");
    case Stats::Att:
        return QStringLiteral("Attack");
    case Stats::Def:
        return QStringLiteral("Defense");
    case Stats::SAtt:
        return QStringLiteral("Special Attack");
    case Stats::SDef:
        return QStringLiteral("Special Defense");
    case Stats::Speed:
        return QStringLiteral("Speed");
    default:
        return QStringLiteral("");
    }
}

QStringList Info::types()
{
    QStringList types;
    types << typeToString(Type::Bug);
    types << typeToString(Type::Dark);
    types << typeToString(Type::Dragon);
    types << typeToString(Type::Electric);
    types << typeToString(Type::Fairy);
    types << typeToString(Type::Fighting);
    types << typeToString(Type::Fire);
    types << typeToString(Type::Flying);
    types << typeToString(Type::Ghost);
    types << typeToString(Type::Grass);
    types << typeToString(Type::Ground);
    types << typeToString(Type::Ice);
    types << typeToString(Type::Normal);
    types << typeToString(Type::Poison);
    types << typeToString(Type::Psychic);
    types << typeToString(Type::Rock);
    types << typeToString(Type::Steel);
    types << typeToString(Type::Water);

    return types;
}

QStringList Info::natures()
{
    QStringList natures;
    natures << natureToString(Nature::Adamant);
    natures << natureToString(Nature::Bashful);
    natures << natureToString(Nature::Brave);
    natures << natureToString(Nature::Bold);
    natures << natureToString(Nature::Calm);
    natures << natureToString(Nature::Careful);
    natures << natureToString(Nature::Docile);
    natures << natureToString(Nature::Gentle);
    natures << natureToString(Nature::Hardy);
    natures << natureToString(Nature::Hasty);
    natures << natureToString(Nature::Impish);
    natures << natureToString(Nature::Jolly);
    natures << natureToString(Nature::Lax);
    natures << natureToString(Nature::Lonely);
    natures << natureToString(Nature::Mild);
    natures << natureToString(Nature::Modest);
    natures << natureToString(Nature::Naive);
    natures << natureToString(Nature::Naughty);
    natures << natureToString(Nature::Quiet);
    natures << natureToString(Nature::Quirky);
    natures << natureToString(Nature::Rash);
    natures << natureToString(Nature::Relaxed);
    natures << natureToString(Nature::Sassy);
    natures << natureToString(Nature::Serious);
    natures << natureToString(Nature::Timid);

    return natures;
}

#pragma once

// Qt headers
#include <QString>

// library headers
#include "dexlib_export.h"

class Info
{
public:
    enum class Type
    {
        NONE = 0,
        Bug,
        Dark,
        Dragon,
        Electric,
        Fairy,
        Fighting,
        Fire,
        Flying,
        Ghost,
        Grass,
        Ground,
        Ice,
        Normal,
        Poison,
        Psychic,
        Rock,
        Steel,
        Water
    };

    enum class Nature {
        Adamant = 0,
        Bashful,
        Brave,
        Bold,
        Calm,
        Careful,
        Docile,
        Gentle,
        Hardy,
        Hasty,
        Impish,
        Jolly,
        Lax,
        Lonely,
        Mild,
        Modest,
        Naive,
        Naughty,
        Quiet,
        Quirky,
        Rash,
        Relaxed,
        Sassy,
        Serious,
        Timid,
        ERROR
    };

    static QString typeToString(const Type &type);
    static Type    stringToType(const QString &type);
    static QList<Type> stringListToTypes(const QStringList &types);

    static QString natureToString(const Nature &nature);
    static Nature stringToNature(const QString &nature);

    static QStringList types();
    static QStringList natures();

private:
    Info();
};

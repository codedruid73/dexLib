#pragma once

// Qt headers
#include <QList>

// library headers
#include "dexlib_export.h"

class DEXLIB_EXPORT TypeInfo
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

    explicit TypeInfo(const Type type,
                      const QList<Type> &effective,
                      const QList<Type> &ineffective,
                      const QList<Type> &noEffect);
    ~TypeInfo();

    Type type() const;
    float multiplier(Type other) const; // Return the damage multiplier of this type on other type

    static QString toString(Type type);
    static Type    toType(const QString &type);

private:
    const Type m_type;
    const QList<Type> m_effective;
    const QList<Type> m_ineffective;
    const QList<Type> m_noEffect;

};

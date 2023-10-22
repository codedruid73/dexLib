#include "typeinfo.h"

TypeInfo::TypeInfo(Type type,
                   const QList<Type> &effective,
                   const QList<Type> &ineffective,
                   const QList<Type> &noEffect):
    m_type(type),
    m_effective(effective),
    m_ineffective(ineffective),
    m_noEffect(noEffect)
{

}

TypeInfo::~TypeInfo()
{

}

TypeInfo::Type TypeInfo::type() const
{
    return m_type;
}

float TypeInfo::multiplier(Type other) const
{
    if (m_effective.contains(other))
        return 2.0f;
    if (m_ineffective.contains(other))
        return 0.5f;
    if (m_noEffect.contains(other))
        return 0.0f;
    return 1.0f;
}

QString TypeInfo::toString(Type type)
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

TypeInfo::Type TypeInfo::toType(const QString &type)
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

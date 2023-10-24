#include "item.h"

Item::Item(const QString &name,
           const Type    &type,
           const QString &description):
    m_name(name),
    m_type(type),
    m_description(description)
{

}

Item::Item(const Item &other) noexcept:
    Item(other.m_name,
         other.m_type,
         other.m_description)
{

}

Item::~Item()
{

}

QString Item::name() const
{
    return m_name;
}

Item::Type Item::type() const
{
    return m_type;
}

QString Item::description() const
{
    return m_description;
}

const QString Item::typeToString(const Type &type)
{
    switch (type) {
    case Type::PokeBalls:
        return QStringLiteral("PokeBalls");
    case Type::Medicine:
        return QStringLiteral("Medicine");
    case Type::BattleItems:
        return QStringLiteral("BattleItems");
    case Type::GeneralItems:
        return QStringLiteral("GeneralItems");
    case Type::HoldItems:
        return QStringLiteral("HoldItems");
    case Type::KeyItems:
        return QStringLiteral("KeyItems");
    case Type::Berries:
        return QStringLiteral("Berries");
    case Type::Machines:
        return QStringLiteral("Machines");
    case Type::Unknown:
    default:
        return QStringLiteral("Unknown");
    }
}

const Item::Type Item::stringToType(const QString &str)
{
    if (str == QStringLiteral("PokeBalls"))
        return Type::PokeBalls;
    if (str == QStringLiteral("Medicine"))
        return Type::Medicine;
    if (str == QStringLiteral("BattleItems"))
        return Type::BattleItems;
    if (str == QStringLiteral("GeneralItems"))
        return Type::GeneralItems;
    if (str == QStringLiteral("HoldItems"))
        return Type::HoldItems;
    if (str == QStringLiteral("KeyItems"))
        return Type::KeyItems;
    if (str == QStringLiteral("Berries"))
        return Type::Berries;
    if (str == QStringLiteral("Machines"))
        return Type::Machines;

    return Type::Unknown;
}

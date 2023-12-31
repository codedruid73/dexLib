#include "move.h"

Move::Move(const QString &name,
           const Category &category,
           const Info::Type &type,
           const ushort &power,
           const ushort &accuracy,
           const ushort &pp,
           const QString &description):
    m_name(name),
    m_category(category),
    m_type(type),
    m_power(power),
    m_accuracy(accuracy),
    m_pp(pp),
    m_description(description)
{

}

Move::Move(const Move &other) noexcept:
    Move(other.m_name,
         other.m_category,
         other.m_type,
         other.m_power,
         other.m_accuracy,
         other.m_pp,
         other.m_description)
{

}

Move::~Move()
{

}

QString Move::name() const
{
    return m_name;
}

Move::Category Move::category() const
{
    return m_category;
}

Info::Type Move::type() const
{
    return m_type;
}

ushort Move::power() const
{
    return m_power;
}

ushort Move::accuracy() const
{
    return m_accuracy;
}

ushort Move::pp() const
{
    return m_pp;
}

QString Move::description() const
{
    return m_description;
}

const QString Move::categoryToString(const Category &category)
{
    switch (category) {
    case Category::Physical:
        return QStringLiteral("Physical");
    case Category::Special:
        return QStringLiteral("Special");
    case Category::NonDamaging:
        return QStringLiteral("Non-Damaging");
    case Category::Unknown:
    default:
        return QStringLiteral("Unknown");
    }
}

const Move::Category Move::stringToCategory(const QString &str)
{
    if (str == QStringLiteral("Physical"))
        return Category::Physical;
    if (str == QStringLiteral("Special"))
        return Category::Special;
    if (str == QStringLiteral("Non-Damaging"))
        return Category::NonDamaging;

    return Category::Unknown;
}

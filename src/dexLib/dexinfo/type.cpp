#include "type.h"

Type::Type(Info::Type type,
           const QList<Info::Type> &effective,
           const QList<Info::Type> &ineffective,
           const QList<Info::Type> &noEffect):
    m_type(type),
    m_effective(effective),
    m_ineffective(ineffective),
    m_noEffect(noEffect)
{

}

Type::~Type()
{

}

Info::Type Type::type() const
{
    return m_type;
}

float Type::multiplier(Info::Type other) const
{
    if (m_effective.contains(other))
        return 2.0f;
    if (m_ineffective.contains(other))
        return 0.5f;
    if (m_noEffect.contains(other))
        return 0.0f;
    return 1.0f;
}

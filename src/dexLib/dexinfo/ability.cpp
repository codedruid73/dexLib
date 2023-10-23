#include "ability.h"

Ability::Ability(const QString &name,
                 const QString &description):
    m_name(name),
    m_description(description)
{

}

Ability::Ability(const Ability &other) noexcept:
    Ability(other.m_name, other.m_description)
{

}

Ability::~Ability()
{

}

QString Ability::name() const
{
    return m_name;
}

QString Ability::description() const
{
    return m_description;
}

#include "abilityinfo.h"

AbilityInfo::AbilityInfo(const QString &name,
                         const QString &description):
    m_name(name),
    m_description(description)
{

}

AbilityInfo::AbilityInfo(const AbilityInfo &other) noexcept:
    AbilityInfo(other.m_name, other.m_description)
{

}

AbilityInfo::~AbilityInfo()
{

}

QString AbilityInfo::name() const
{
    return m_name;
}

QString AbilityInfo::description() const
{
    return m_description;
}

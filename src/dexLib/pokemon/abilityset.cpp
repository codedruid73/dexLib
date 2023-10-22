#include "abilityset.h"

AbilitySet::AbilitySet(const QSharedPointer<AbilityInfo> &primary,
                       const QSharedPointer<AbilityInfo> &secondary,
                       const QSharedPointer<AbilityInfo> &hidden):
    m_primary(primary),
    m_secondary(secondary),
    m_hidden(hidden),
    m_hasSecond(m_secondary.isNull())
{
    if (m_primary.isNull() || m_hidden.isNull())
    {
        // critical!
    }
}

bool AbilitySet::hasSecondary() const
{
    return m_hasSecond;
}

QSharedPointer<AbilityInfo> AbilitySet::primary() const
{
    return m_primary;
}

QSharedPointer<AbilityInfo> AbilitySet::secondary() const
{
    return m_secondary;
}

QSharedPointer<AbilityInfo> AbilitySet::hidden() const
{
    return m_hidden;
}


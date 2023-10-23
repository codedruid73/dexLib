#include "abilityset.h"

AbilitySet::AbilitySet(const QSharedPointer<Ability> &primary,
                       const QSharedPointer<Ability> &secondary,
                       const QSharedPointer<Ability> &hidden):
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

QSharedPointer<Ability> AbilitySet::primary() const
{
    return m_primary;
}

QSharedPointer<Ability> AbilitySet::secondary() const
{
    return m_secondary;
}

QSharedPointer<Ability> AbilitySet::hidden() const
{
    return m_hidden;
}


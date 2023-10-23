#pragma once

// Qt headers
#include <QSharedPointer>

// library headers
#include "ability.h"

class AbilitySet
{

public:
    AbilitySet(const  QSharedPointer<Ability> &primary,
               const  QSharedPointer<Ability> &secondary,
               const  QSharedPointer<Ability> &hidden);

    bool hasSecondary() const;

    QSharedPointer<Ability> primary() const;
    QSharedPointer<Ability> secondary() const;
    QSharedPointer<Ability> hidden() const;

private:
    const QSharedPointer<Ability> m_primary;
    const QSharedPointer<Ability> m_secondary;
    const QSharedPointer<Ability> m_hidden;
    const bool m_hasSecond;

};

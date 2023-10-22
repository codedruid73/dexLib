#pragma once

// Qt headers
#include <QSharedPointer>

// library headers
#include "abilityinfo.h"

class AbilitySet
{

public:
    AbilitySet(const  QSharedPointer<AbilityInfo> &primary,
               const  QSharedPointer<AbilityInfo> &secondary,
               const  QSharedPointer<AbilityInfo> &hidden);

    bool hasSecondary() const;

    QSharedPointer<AbilityInfo> primary() const;
    QSharedPointer<AbilityInfo> secondary() const;
    QSharedPointer<AbilityInfo> hidden() const;

private:
    const QSharedPointer<AbilityInfo> m_primary;
    const QSharedPointer<AbilityInfo> m_secondary;
    const QSharedPointer<AbilityInfo> m_hidden;
    const bool m_hasSecond;

};

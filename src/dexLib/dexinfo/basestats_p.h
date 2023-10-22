#pragma once

// Qt headers
#include <QtGlobal>

class BaseStatsPrivate
{
public:
    explicit BaseStatsPrivate(const ushort &hp,
                              const ushort &att,
                              const ushort &def,
                              const ushort &satt,
                              const ushort &sdef,
                              const ushort &speed);
    BaseStatsPrivate(const BaseStatsPrivate &other) noexcept;
    BaseStatsPrivate(BaseStatsPrivate &&other) noexcept;

    const ushort m_hitPoints;
    const ushort m_attack;
    const ushort m_defense;
    const ushort m_specialAttack;
    const ushort m_specialDefense;
    const ushort m_speed;
};

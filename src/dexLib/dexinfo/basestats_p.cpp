#include "basestats_p.h"

BaseStatsPrivate::BaseStatsPrivate(const ushort &hp,
                                   const ushort &att,
                                   const ushort &def,
                                   const ushort &satt,
                                   const ushort &sdef,
                                   const ushort &speed):
    m_hitPoints(hp),
    m_attack(att),
    m_defense(def),
    m_specialAttack(satt),
    m_specialDefense(sdef),
    m_speed(speed)
{

}

BaseStatsPrivate::BaseStatsPrivate(const BaseStatsPrivate &other) noexcept:
    m_hitPoints(other.m_hitPoints),
    m_attack(other.m_attack),
    m_defense(other.m_defense),
    m_specialAttack(other.m_specialAttack),
    m_specialDefense(other.m_specialDefense),
    m_speed(other.m_speed)
{

}

BaseStatsPrivate::BaseStatsPrivate(BaseStatsPrivate &&other) noexcept:
    m_hitPoints(other.m_hitPoints),
    m_attack(other.m_attack),
    m_defense(other.m_defense),
    m_specialAttack(other.m_specialAttack),
    m_specialDefense(other.m_specialDefense),
    m_speed(other.m_speed)
{

}

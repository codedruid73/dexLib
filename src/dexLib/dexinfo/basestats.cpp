#include "basestats.h"

#include "basestats_p.h"


BaseStats::BaseStats(const ushort &hp,
                     const ushort &att,
                     const ushort &def,
                     const ushort &satt,
                     const ushort &sdef,
                     const ushort &speed):
    m_pimpl(new BaseStatsPrivate(hp, att, def, satt, sdef, speed))
{

}

BaseStats::BaseStats(const BaseStats &other) noexcept:
    m_pimpl(new BaseStatsPrivate(*other.m_pimpl))
{

}

BaseStats::BaseStats(BaseStats &&other) noexcept:
    m_pimpl(other.m_pimpl.get())
{

}

BaseStats::~BaseStats()
{

}

ushort BaseStats::baseHp() const
{
    return m_pimpl->m_hitPoints;
}

ushort BaseStats::baseAtt() const
{
    return m_pimpl->m_attack;
}

ushort BaseStats::baseDef() const
{
    return m_pimpl->m_defense;
}

ushort BaseStats::baseSAtt() const
{
    return m_pimpl->m_specialAttack;
}

ushort BaseStats::baseSDef() const
{
    return m_pimpl->m_specialDefense;
}

ushort BaseStats::baseSpeed() const
{
    return m_pimpl->m_speed;
}

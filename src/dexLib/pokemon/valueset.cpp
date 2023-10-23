#include "valueset.h"

ValueSet::ValueSet()
{

}

ValueSet::ValueSet(const ushort &hp,
                   const ushort &att,
                   const ushort &def,
                   const ushort &satt,
                   const ushort &sdef,
                   const ushort &speed):
    m_hp(hp),
    m_attack(att),
    m_defense(def),
    m_specialAttack(satt),
    m_specialDefense(sdef),
    m_speed(speed)
{

}

ValueSet::ValueSet(const ValueSet &other) noexcept:
    m_hp(other.m_hp),
    m_attack(other.m_attack),
    m_defense(other.m_defense),
    m_specialAttack(other.m_specialAttack),
    m_specialDefense(other.m_specialDefense),
    m_speed(other.m_speed)
{

}

ValueSet::ValueSet(ValueSet &&other) noexcept:
    m_hp(other.m_hp),
    m_attack(other.m_attack),
    m_defense(other.m_defense),
    m_specialAttack(other.m_specialAttack),
    m_specialDefense(other.m_specialDefense),
    m_speed(other.m_speed)
{

}

ValueSet::~ValueSet()
{

}


ValueSet &ValueSet::operator =(const ValueSet &other) noexcept
{
    if (&other != this)
    {
        this->setHp(other.hp());
        this->setAtt(other.att());
        this->setDef(other.def());
        this->setSAtt(other.sAtt());
        this->setSDef(other.sDef());
        this->setSpeed(other.speed());
    }

    return *this;
}

ValueSet &ValueSet::operator =(ValueSet &&other) noexcept
{
    this->setHp(other.hp());
    this->setAtt(other.att());
    this->setDef(other.def());
    this->setSAtt(other.sAtt());
    this->setSDef(other.sDef());
    this->setSpeed(other.speed());

    return *this;
}



ushort ValueSet::hp() const
{
    return m_hp;
}

ushort ValueSet::att() const
{
    return m_attack;
}

ushort ValueSet::def() const
{
    return m_defense;
}

ushort ValueSet::sAtt() const
{
    return m_specialAttack;
}

ushort ValueSet::sDef() const
{
    return m_specialDefense;
}

ushort ValueSet::speed() const
{
    return m_speed;
}

void ValueSet::setHp(const ushort &hp)
{
    m_hp = hp;
}

void ValueSet::setAtt(const ushort &att)
{
    m_attack = att;
}

void ValueSet::setDef(const ushort &def)
{
    m_defense = def;
}

void ValueSet::setSAtt(const ushort &satt)
{
    m_specialAttack = satt;
}

void ValueSet::setSDef(const ushort &sdef)
{
    m_specialDefense = sdef;
}

void ValueSet::setSpeed(const ushort &speed)
{
    m_speed = speed;
}

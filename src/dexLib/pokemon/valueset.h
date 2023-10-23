#pragma once

// Qt headers
#include <QtGlobal>

// library headers
#include "dexlib_export.h"

class DEXLIB_EXPORT ValueSet
{

public:
    ValueSet();
    explicit ValueSet(const ushort &hp,
                      const ushort &att,
                      const ushort &def,
                      const ushort &satt,
                      const ushort &sdef,
                      const ushort &speed);
    ValueSet(const ValueSet &other) noexcept;
    ValueSet(ValueSet &&other) noexcept;
    ~ValueSet();

    ValueSet &operator=(const ValueSet &other) noexcept;
    ValueSet &operator=(ValueSet &&other) noexcept;

    ushort hp() const;
    ushort att() const;
    ushort def() const;
    ushort sAtt() const;
    ushort sDef() const;
    ushort speed() const;

    void setHp(const ushort &hp);
    void setAtt(const ushort &att);
    void setDef(const ushort &def);
    void setSAtt(const ushort &satt);
    void setSDef(const ushort &sdef);
    void setSpeed(const ushort &speed);

private:
    ushort m_hp;
    ushort m_attack;
    ushort m_defense;
    ushort m_specialAttack;
    ushort m_specialDefense;
    ushort m_speed;
};

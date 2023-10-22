#pragma once

// C++ headers
#include <memory>

// Qt headers
#include <QtGlobal>

// library headers
#include "dexlib_export.h"

class BaseStatsPrivate;

class DEXLIB_EXPORT BaseStats
{

public:
    explicit BaseStats(const ushort &hp,
                       const ushort &att,
                       const ushort &def,
                       const ushort &satt,
                       const ushort &sdef,
                       const ushort &speed);
    BaseStats(const BaseStats &other) noexcept;
    BaseStats(BaseStats &&other) noexcept;
    ~BaseStats();

    ushort baseHp() const;
    ushort baseAtt() const;
    ushort baseDef() const;
    ushort baseSAtt() const;
    ushort baseSDef() const;
    ushort baseSpeed() const;

private:
    std::unique_ptr<BaseStatsPrivate> m_pimpl;
};

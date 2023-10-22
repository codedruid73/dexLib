#pragma once

// Qt headers
#include <QtGlobal>
#include <QString>
#include <QMap>

// library headers
#include "dexlib_export.h"
#include "typeinfo.h"
#include "basestats.h"

//class BaseStats;
//class AbilitySet;

class DEXLIB_EXPORT PokemonInfo{

public:
    explicit PokemonInfo(const ushort              &id,
                         const ushort              &dexNumber,
                         const QString             &name,
                         const TypeInfo::Type      &primaryType,
                         const TypeInfo::Type      &secondaryType,
                         const BaseStats           &stats,
                         const QString             &species,
                         const QString             &description,
                         const QMap<QString, bool> &abilities);
    PokemonInfo(const PokemonInfo &other) noexcept;
    PokemonInfo(PokemonInfo &&other) noexcept;
    ~PokemonInfo();

    const ushort id() const;
    const ushort number() const;
    const QString name() const;
    const QString primaryType() const;
    const QString secondaryType() const;
    const BaseStats baseStats() const;
    const QString species() const;
    const QString description() const;

private:
    const ushort  m_uid;
    const ushort  m_dexNumber;
    const QString m_name;
    const TypeInfo::Type m_primaryType;
    const TypeInfo::Type m_secondaryType;
    const BaseStats m_baseStats;
    const QString m_species;
    const QString m_description;
    const QMap<QString, bool> m_abilities;
    // Evolution
    // info + egg
    // gender
    // Images ?
};

#include "pokemoninfo.h"

PokemonInfo::PokemonInfo(const ushort &id,
                         const ushort &dexNumber,
                         const QString &name,
                         const TypeInfo::Type &primaryType,
                         const TypeInfo::Type &secondaryType,
                         const BaseStats &stats,
                         const QString &species,
                         const QString &description,
                         const QMap<QString, bool> &abilities):
    m_uid(id),
    m_dexNumber(dexNumber),
    m_name(name),
    m_primaryType(primaryType),
    m_secondaryType(secondaryType),
    m_baseStats(stats),
    m_species(species),
    m_description(description),
    m_abilities(abilities)
{

}

PokemonInfo::PokemonInfo(const PokemonInfo &other) noexcept:
    m_uid(other.m_uid),
    m_dexNumber(other.m_dexNumber),
    m_name(other.m_name),
    m_primaryType(other.m_primaryType),
    m_secondaryType(other.m_secondaryType),
    m_baseStats(other.m_baseStats),
    m_species(other.m_species),
    m_description(other.m_description),
    m_abilities(other.m_abilities)
{

}

PokemonInfo::PokemonInfo(PokemonInfo &&other) noexcept:
    m_uid(other.m_uid),
    m_dexNumber(other.m_dexNumber),
    m_name(other.m_name),
    m_primaryType(other.m_primaryType),
    m_secondaryType(other.m_secondaryType),
    m_baseStats(other.m_baseStats),
    m_species(other.m_species),
    m_description(other.m_description),
    m_abilities(other.m_abilities)
{

}

PokemonInfo::~PokemonInfo()
{

}

const ushort PokemonInfo::id() const
{
    return m_uid;
}

const ushort PokemonInfo::number() const
{
    return m_dexNumber;
}

const QString PokemonInfo::name() const
{
    return m_name;
}

const QString PokemonInfo::primaryType() const
{
    return TypeInfo::toString(m_primaryType);
}

const QString PokemonInfo::secondaryType() const
{
    return TypeInfo::toString(m_secondaryType);
}

const BaseStats PokemonInfo::baseStats() const
{
    return m_baseStats;
}

const QString PokemonInfo::species() const
{
    return m_species;
}

const QString PokemonInfo::description() const
{
    return m_description;
}


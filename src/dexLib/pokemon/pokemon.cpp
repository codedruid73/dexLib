#include "pokemon.h"

#include <QUuid>
#include <QDebug>

Pokemon::Pokemon(const QSharedPointer<PokemonInfo> &info, const QString &uuid):
    m_info(info),
    m_uuid(uuid.isEmpty() ? QUuid::createUuid().toString() : uuid),
    m_level(),
    m_gender(PokemonInfo::Gender::Invalid),
    m_shiny(false),
    m_teraType(Info::stringToType(info->primaryType())),
    m_item(""),
    m_ability(""),
    m_evs(),
    m_ivs(),
    m_nature("Serious"),
    m_moves(QStringList())
{
    qDebug() << "created pokemon with uuid" << m_uuid;
}

const bool Pokemon::isValid()
{
    return !m_info.isNull() && m_gender != PokemonInfo::Gender::Invalid;
}

const QSharedPointer<PokemonInfo> Pokemon::info()
{
    return m_info;
}

const QString Pokemon::uuid()
{
    return m_uuid;
}

const ushort Pokemon::level()
{
    return m_level;
}

const QString Pokemon::gender()
{
    return PokemonInfo::genderToString(m_gender);
}

const bool Pokemon::shiny()
{
    return m_shiny;
}

const QString Pokemon::teraType()
{
    return Info::typeToString(m_teraType);
}

const QString Pokemon::item()
{
    return m_item;
}

const QString Pokemon::ability()
{
    return m_ability;
}

const ValueSet Pokemon::evs()
{
    return m_evs;
}

const ValueSet Pokemon::ivs()
{
    return m_ivs;
}

const QString Pokemon::nature()
{
    return m_nature;
}

const QStringList Pokemon::moves()
{
    return m_moves;
}

void Pokemon::setLevel(const ushort &level)
{
    if(level < 101)
        m_level = level;

    // Error!
}

void Pokemon::setGender(const QString &gender)
{
    if (PokemonInfo::stringToGender(gender) != PokemonInfo::Gender::Invalid)
        m_gender = PokemonInfo::stringToGender(gender);

    // Error!
}

void Pokemon::setShiny(bool shiny)
{
    m_shiny = shiny;
}

void Pokemon::setTeraType(Info::Type teraType)
{
    if (teraType != Info::Type::NONE)
        m_teraType = teraType;

    // Error!
}

void Pokemon::setItem(const QString &item)
{
    // check if item exists
    m_item = item;
}

void Pokemon::setAbility(const QString &ability)
{
    // check if ability is valid
    m_ability = ability;
}

void Pokemon::setEvs(const ValueSet &evs)
{
    m_evs = evs;
}

void Pokemon::setIvs(const ValueSet &ivs)
{
    m_ivs = ivs;
}

void Pokemon::setNature(const QString &nature)
{
    // check if natue is valid
    m_nature = nature;
}

void Pokemon::setMoves(const QStringList &moves)
{
    // check if moves are valid
    if (moves.size() < 5)
        m_moves = moves;

    // Error
}








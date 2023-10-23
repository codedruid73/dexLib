#pragma once

// Qt headers
#include <QSharedPointer>

// library headers
#include "dexlib_export.h"
#include "pokemoninfo.h"
#include "valueset.h"

class DEXLIB_EXPORT Pokemon
{

public:
    Pokemon(const QSharedPointer<PokemonInfo> &info,
            const QString &uuid = QString());

    const bool isValid();
    const QSharedPointer<PokemonInfo> info();
    const QString uuid();

    const ushort      level();
    const QString     gender();
    const bool        shiny();
    const QString     teraType();
    const QString     item();
    const QString     ability();
    const ValueSet    evs();
    const ValueSet    ivs();
    const QString     nature();
    const QStringList moves();

    void setLevel(const ushort &level);
    void setGender(const QString &gender);
    void setShiny(bool shiny);
    void setTeraType(Info::Type teraType);
    void setItem(const QString &item);
    void setAbility(const QString &ability);
    void setEvs(const ValueSet &evs);
    void setIvs(const ValueSet &ivs);
    void setNature(const QString &nature);
    void setMoves(const QStringList &moves);

private:
    const QSharedPointer<PokemonInfo> m_info;
    const QString m_uuid;

    ushort m_level;
    PokemonInfo::Gender m_gender;
    bool m_shiny;
    Info::Type m_teraType; // game ?

    QString m_item; // game ?
    QString m_ability; // game

    ValueSet m_evs;
    ValueSet m_ivs;
    QString m_nature;

    QStringList m_moves; // game
};


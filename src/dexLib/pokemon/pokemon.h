#pragma once

// Qt headers
#include <QSharedPointer>

// library headers
#include "dexlib_export.h"
#include "pokemoninfo.h"

class Pokemon
{
public:
    Pokemon(const QSharedPointer<PokemonInfo> &info);


private:
    const QSharedPointer<PokemonInfo> m_info;



    // gender
    // shiny ??
    // item
    // ability
    // level
    // tera type
    // evs
    // ivs
    // Nature -> QString
    // Moves ->

    ushort m_level;
};


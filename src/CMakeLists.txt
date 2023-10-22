# DexLib
set(DexLib_PUBLIC_HEADERS
    dexLib/item/item.h

    dexLib/dexinfo/basestats.h
    dexLib/pokemon/pokemoninfo.h
    dexLib/dexinfo/abilityinfo.h
    dexLib/dexinfo/typeinfo.h

    dexLib/pokemon/abilityset.h

    dexLib/dexreaders/pokemondex.h
    dexLib/dexreaders/reader.h

    dexLib/move/move.h

    dexLib/pokemon/pokemon.h

)
set(DexLib_PRIVATE_HEADERS
    dexLib/dexinfo/basestats_p.h
)
set(DexLib_SOURCES
    dexLib/item/item.cpp

    dexLib/dexinfo/basestats.cpp
    dexLib/dexinfo/basestats_p.cpp
    dexLib/pokemon/pokemoninfo.cpp
    dexLib/dexinfo/abilityinfo.cpp
    dexLib/dexinfo/typeinfo.cpp

    dexLib/dexreaders/pokemondex.cpp
    dexLib/dexreaders/reader.cpp

    #dexLib/pokemon/pkmtype.cpp

    dexLib/pokemon/abilityset.cpp

    dexLib/move/move.cpp

    dexLib/pokemon/pokemon.cpp
)

createlib(
    NAME DexLib STATIC
    VERSION 1.0.0
    NAMESPACE CD
    SOURCES ${DexLib_SOURCES}
    PRIVATE_HEADERS ${DexLib_PRIVATE_HEADERS}
    PUBLIC_HEADERS ${DexLib_PUBLIC_HEADERS}
    PUBLIC_DEPS Qt6::Core
    GENERATE_PACKAGE
)

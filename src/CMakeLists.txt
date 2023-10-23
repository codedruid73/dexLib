# DexLib
set(DexLib_PUBLIC_HEADERS
    dexLib/dexinfo/ability.h
    dexLib/dexinfo/basestats.h
    dexLib/dexinfo/info.h
    dexLib/dexinfo/nature.h
    dexLib/dexinfo/type.h

    dexLib/item/item.h
    dexLib/move/move.h

    dexLib/dexreaders/pokemondex.h
    dexLib/dexreaders/typedex.h
    dexLib/dexreaders/pokemonreader.h
    dexLib/dexreaders/reader.h

    dexLib/pokemon/abilityset.h
    dexLib/pokemon/pokemon.h
    dexLib/pokemon/valueset.h

    dexLib/pokemon/pokemoninfo.h
)
set(DexLib_PRIVATE_HEADERS
    dexLib/dexinfo/basestats_p.h
)
set(DexLib_SOURCES
    dexLib/dexinfo/ability.cpp
    dexLib/dexinfo/basestats.cpp
    dexLib/dexinfo/basestats_p.cpp
    dexLib/dexinfo/info.cpp
    dexLib/dexinfo/nature.cpp
    dexLib/dexinfo/type.cpp

    dexLib/item/item.cpp
    dexLib/move/move.cpp

    dexLib/dexreaders/pokemondex.cpp
    dexLib/dexreaders/typedex.cpp
    dexLib/dexreaders/pokemonreader.cpp
    dexLib/dexreaders/reader.cpp

    dexLib/pokemon/abilityset.cpp
    dexLib/pokemon/pokemon.cpp
    dexLib/pokemon/valueset.cpp

    dexLib/pokemon/pokemoninfo.cpp
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

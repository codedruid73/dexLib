# DexLib
set(DexLib_PUBLIC_HEADERS
    dexLib/dexinfo/ability.h
    dexLib/dexinfo/basestats.h
    dexLib/dexinfo/info.h
    dexLib/dexinfo/item.h
    dexLib/dexinfo/move.h
    dexLib/dexinfo/nature.h
    dexLib/dexinfo/pokemoninfo.h
    dexLib/dexinfo/type.h    

    dexLib/dexreaders/pokemondex.h
    dexLib/dexreaders/pokemonreader.h
    dexLib/dexreaders/reader.h
    dexLib/dexreaders/typedex.h

    dexLib/pokemon/abilityset.h
    dexLib/pokemon/pokemon.h
    dexLib/pokemon/valueset.h
)
set(DexLib_PRIVATE_HEADERS
    dexLib/dexinfo/basestats_p.h
)
set(DexLib_SOURCES
    dexLib/dexinfo/ability.cpp
    dexLib/dexinfo/basestats.cpp
    dexLib/dexinfo/basestats_p.cpp
    dexLib/dexinfo/info.cpp
    dexLib/dexinfo/item.cpp
    dexLib/dexinfo/move.cpp
    dexLib/dexinfo/nature.cpp
    dexLib/dexinfo/pokemoninfo.cpp
    dexLib/dexinfo/type.cpp

    dexLib/dexreaders/pokemondex.cpp
    dexLib/dexreaders/pokemonreader.cpp
    dexLib/dexreaders/reader.cpp
    dexLib/dexreaders/typedex.cpp

    dexLib/pokemon/abilityset.cpp
    dexLib/pokemon/pokemon.cpp
    dexLib/pokemon/valueset.cpp
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

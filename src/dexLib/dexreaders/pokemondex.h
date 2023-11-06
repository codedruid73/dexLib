#pragma once

// Qt headers
#include <QObject>
#include <QDir>

// library headers
#include "dexlib_export.h"
#include "dex.h"

class PokemonInfo;

class DEXLIB_EXPORT PokemonDex : public Dex<PokemonInfo>
{

public:
    PokemonDex(const QDir &dir);
    PokemonDex(const PokemonDex &other) = delete;
    ~PokemonDex();

private:
    virtual QSharedPointer<PokemonInfo> create(const QJsonObject &object);
    virtual const QString key(const QJsonObject &object);
};

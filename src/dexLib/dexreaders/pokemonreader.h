#pragma once

// Qt headers
#include <QString>
#include <QSharedPointer>

// library headers
#include "dexlib_export.h"

class QJsonObject;
class Pokemon;
class ValueSet;

class DEXLIB_EXPORT PokemonReader
{
public:
    static QSharedPointer<Pokemon> read(const QString &filepath);
    static bool write(const QString &filepath, const QSharedPointer<Pokemon> &pkm);

private:
    PokemonReader();

    static const QJsonObject createStats(const ValueSet &evs,
                                         const ValueSet &ivs,
                                         const QString  &nature);
};

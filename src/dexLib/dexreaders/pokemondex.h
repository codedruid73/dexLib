#pragma once

// Qt headers
#include <QObject>

// library headers
#include "dexlib_export.h"

class PokemonInfo;

class DEXLIB_EXPORT PokemonDex : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(PokemonDex)

public:
    PokemonDex(QObject *parent = nullptr);
    PokemonDex(PokemonDex &other) = delete;
    ~PokemonDex();

    bool read();
    QList<QSharedPointer<PokemonInfo>> dex() const;
    const QStringList names() const;

private:
    QList<QSharedPointer<PokemonInfo>> m_dex;

    QSharedPointer<PokemonInfo> create(const QJsonObject &object);
};

typedef QList<QSharedPointer<PokemonInfo>> PokemonInfoList;

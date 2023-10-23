#pragma once

// Qt headers
#include <QObject>
#include <QDir>

// library headers
#include "dexlib_export.h"

class PokemonInfo;

class DEXLIB_EXPORT PokemonDex : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(PokemonDex)

public:
    PokemonDex(const QDir &dir, QObject *parent = nullptr);
    PokemonDex(PokemonDex &other) = delete;
    ~PokemonDex();

    bool read();
    QList<QSharedPointer<PokemonInfo>> dex() const;
    QSharedPointer<PokemonInfo> info(const QString &name) const; // TODO: form
    const QStringList list() const;

private:
    QDir m_directory;
    QList<QSharedPointer<PokemonInfo>> m_dex;

    QSharedPointer<PokemonInfo> create(const QJsonObject &object);
};

typedef QList<QSharedPointer<PokemonInfo>> PokemonInfoList;

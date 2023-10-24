#pragma once

// Qt headers
#include <QDir>

// library headers
#include "dexlib_export.h"
#include "dex.h"

class Move;

class DEXLIB_EXPORT MoveDex : public Dex<Move>
{

public:
    explicit MoveDex(const QDir &dir);
    MoveDex(const MoveDex &other) = delete;
    ~MoveDex();

private:
    virtual QSharedPointer<Move> create(const QJsonObject &object);
    virtual const QString key(const QJsonObject &object);
};

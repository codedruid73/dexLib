#pragma once

// Qt headers
#include <QDir>

// library headers
#include "dexlib_export.h"
#include "dex.h"

class Nature;

class DEXLIB_EXPORT NatureDex: public Dex<Nature>
{

public:
    explicit NatureDex(const QDir &dir);
    NatureDex(const NatureDex &other) = delete;
    ~NatureDex();

private:
    virtual QSharedPointer<Nature> create(const QJsonObject &object);
    virtual const QString key(const QJsonObject &object);
};

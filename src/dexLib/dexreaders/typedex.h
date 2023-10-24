#pragma once

// Qt headers
#include <QDir>

// library headers
#include "dexlib_export.h"
#include "dex.h"

class Type;

class DEXLIB_EXPORT TypeDex : public Dex<Type>
{

public:
    explicit TypeDex(const QDir &dir);
    TypeDex(const TypeDex &other) = delete;
    ~TypeDex();

private:
    virtual QSharedPointer<Type> create(const QJsonObject &object);
    virtual const QString key(const QJsonObject &object);
};


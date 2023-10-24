#pragma once

// Qt headers
#include <QDir>

// library headers
#include "dexlib_export.h"
#include "dex.h"

class Ability;

class DEXLIB_EXPORT AbilityDex : public Dex<Ability>
{

public:
    explicit AbilityDex(const QDir &dir);
    AbilityDex(const AbilityDex &other) = delete;
    ~AbilityDex();

private:
    virtual QSharedPointer<Ability> create(const QJsonObject &object);
    virtual const QString key(const QJsonObject &object);
};


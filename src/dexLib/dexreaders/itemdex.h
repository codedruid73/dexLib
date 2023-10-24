#pragma once

// Qt headers
#include <QDir>

// library headers
#include "dexlib_export.h"
#include "dex.h"

class Item;

class DEXLIB_EXPORT ItemDex : public Dex<Item>
{

public:
    explicit ItemDex(const QDir &dir);
    ItemDex(const ItemDex &other) = delete;
    ~ItemDex();

private:
    virtual QSharedPointer<Item> create(const QJsonObject &object);
    virtual const QString key(const QJsonObject &object);
};

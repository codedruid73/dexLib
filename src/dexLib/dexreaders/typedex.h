#pragma once

// Qt headers
#include <QObject>
#include <QDir>

// library headers
#include "dexlib_export.h"

class Type;

class DEXLIB_EXPORT TypeDex : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(TypeDex)

public:
    TypeDex(const QDir &dir, QObject *parent = nullptr);
    TypeDex(TypeDex &other) = delete;
    ~TypeDex();

    bool read();

private:
    QDir m_dir;
    QList<QSharedPointer<Type>> m_types;

    QSharedPointer<Type> create(const QJsonObject &object);
};


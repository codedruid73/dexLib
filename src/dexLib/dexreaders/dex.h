#pragma once

// Qt headers
#include <QObject>
#include <QDir>

// library headers
#include "dexlib_export.h"

template <typename T>
class DEXLIB_EXPORT Dex
{

public:
    explicit Dex(const QString &filepath);
    Dex(const Dex &other) = delete;
    ~Dex();

    const bool read();

    const QSharedPointer<T> entry(const QString &key);
    const QStringList list();

protected:
    QMap<QString, QSharedPointer<T>> m_dex;
    virtual QSharedPointer<T> create(const QJsonObject &object) = 0;
    virtual const QString key(const QJsonObject &object) = 0;

private:
    const QString m_filepath;

};

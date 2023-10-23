#pragma once

// Qt headers
#include <QString>

// library headers
#include "dexlib_export.h"

class DEXLIB_EXPORT Ability
{

public:
    explicit Ability(const QString &name,
                     const QString &description);
    Ability(const Ability &other) noexcept;
    ~Ability();

    QString name() const;
    QString description() const;

private:
    const QString m_name;
    const QString m_description;
};

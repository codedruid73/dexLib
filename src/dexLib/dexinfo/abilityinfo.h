#pragma once

// Qt headers
#include <QString>

// library headers
#include "dexlib_export.h"

class DEXLIB_EXPORT AbilityInfo
{

public:
    explicit AbilityInfo(const QString &name,
                         const QString &description);
    AbilityInfo(const AbilityInfo &other) noexcept;
    ~AbilityInfo();

    QString name() const;
    QString description() const;

private:
    const QString m_name;
    const QString m_description;
};

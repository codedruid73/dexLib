#pragma once

// Qt headers
#include <QList>

// library headers
#include "dexlib_export.h"
#include "info.h"

class DEXLIB_EXPORT Type
{

public:

    explicit Type(const Info::Type type,
                  const QList<Info::Type> &effective,
                  const QList<Info::Type> &ineffective,
                  const QList<Info::Type> &noEffect);
    ~Type();

    Info::Type type() const;
    float multiplier(Info::Type other) const; // Return the damage multiplier of this type on another type

private:
    const Info::Type m_type;
    const QList<Info::Type> m_effective;
    const QList<Info::Type> m_ineffective;
    const QList<Info::Type> m_noEffect;

};

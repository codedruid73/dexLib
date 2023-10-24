#pragma once

// Qt headers
#include <QString>

// library headers
#include "dexlib_export.h"
#include "info.h"

class DEXLIB_EXPORT Nature
{
public:
    explicit Nature(const Info::Nature nature,
                    const double &hp,
                    const double &att,
                    const double &def,
                    const double &sAtt,
                    const double &sDef,
                    const double &speed,
                    const QString &summary);
    ~Nature();

    static QStringList list();

private:
    const Info::Nature m_nature;
    const double m_hp;
    const double m_att;
    const double m_def;
    const double m_sAtt;
    const double m_sDef;
    const double m_speed;
    const QString m_summary;
};

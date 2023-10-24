#pragma once

// Qt headers
#include <QString>

// library headers
#include "dexlib_export.h"
#include "info.h"

class DEXLIB_EXPORT Nature
{
    explicit Nature(const Info::Nature nature,
                    const float &hp,
                    const float &att,
                    const float &def,
                    const float &sAtt,
                    const float &sDef,
                    const float &speed,
                    const QString &summary);
    ~Nature();

public:
    static QStringList list();

private:
    const Info::Nature m_nature;
    const float m_hp;
    const float m_att;
    const float m_def;
    const float m_sAtt;
    const float m_sDef;
    const float m_speed;
    const QString m_summary;
};

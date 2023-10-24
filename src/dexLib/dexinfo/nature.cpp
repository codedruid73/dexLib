#include "nature.h"

Nature::Nature(const Info::Nature nature,
               const double &hp,
               const double &att,
               const double &def,
               const double &sAtt,
               const double &sDef,
               const double &speed,
               const QString &summary):
    m_nature(nature),
    m_hp(hp),
    m_att(att),
    m_def(def),
    m_sAtt(sAtt),
    m_sDef(sDef),
    m_speed(speed),
    m_summary(summary)
{

}

Nature::~Nature()
{

}

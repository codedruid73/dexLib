#include "nature.h"

Nature::Nature(const Info::Nature nature,
               const float &hp,
               const float &att,
               const float &def,
               const float &sAtt,
               const float &sDef,
               const float &speed):
    m_nature(nature),
    m_hp(hp),
    m_att(att),
    m_def(def),
    m_sAtt(sAtt),
    m_sDef(sDef),
    m_speed(speed)
{

}

Nature::~Nature()
{

}

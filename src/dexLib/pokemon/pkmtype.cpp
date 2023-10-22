#include "pkmtype.h"

#include "typeinfo.h"

PkmType::PkmType(const TypeInfo &primary,
                 const TypeInfo &secondary):
    m_primary(primary),
    m_secondary(secondary)
{

}

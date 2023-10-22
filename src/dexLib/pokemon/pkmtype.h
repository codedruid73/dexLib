#pragma once

// library headers
#include "dexlib_export.h"

#include "typeinfo.h"

class PkmType
{
public:
    PkmType(const TypeInfo &primary,
            const TypeInfo &secondary = TypeInfo());

private:
    const TypeInfo m_primary;
    const TypeInfo m_secondary;
};


#pragma once

// Qt headers
#include <QString>

// library headers
#include "dexlib_export.h"

class DEXLIB_EXPORT Item{

public:
    enum class Type
    {
        PokeBalls,
        Medicine,
        BattleItems,
        GeneralItems,
        HoldItems,
        KeyItems,
        Berries,
        Machines
    };

    explicit Item(const ushort  &id,
                  const QString &name,
                  const Type    &type,
                  const QString &description);
    Item(const Item &other) noexcept;
    ~Item();

    ushort  id() const;
    QString name() const;
    Type    type() const;
    QString description() const;

private:
    const ushort    m_id;
    const QString   m_name;
    const Type      m_type;
    const QString   m_description;
};

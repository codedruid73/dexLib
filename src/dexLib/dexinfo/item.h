#pragma once

// Qt headers
#include <QString>

// library headers
#include "dexlib_export.h"

class DEXLIB_EXPORT Item{

public:
    enum class Type
    {
        PokeBalls = 0,
        Medicine,
        BattleItems,
        GeneralItems,
        HoldItems,
        KeyItems,
        Berries,
        Machines,
        Unknown
    };

    explicit Item(const QString &name,
                  const Type    &type,
                  const QString &description);
    Item(const Item &other) noexcept;
    ~Item();

    QString name() const;
    Type    type() const;
    QString description() const;

    static const QString typeToString(const Type &type);
    static const Type stringToType(const QString &str);

private:
    const QString   m_name;
    const Type      m_type;
    const QString   m_description;
};

#pragma once

// Qt headers
#include <QtGlobal>
#include <QString>

// library headers
#include "dexlib_export.h"
#include "typeinfo.h"

class DEXLIB_EXPORT Move{

public:
    enum class Category
    {
        Physical,
        Special,
        NonEDamaging
    };

    explicit Move(const QString         &name,
                  const Category        &category,
                  const TypeInfo::Type  &type,
                  const ushort          &power,
                  const ushort          &accuracy,
                  const ushort          &pp,
                  const QString         &description);
    Move(const Move &other) noexcept;
    ~Move();

    QString         name() const;
    Category        category() const;
    TypeInfo::Type  type() const;
    ushort          power() const;
    ushort          accuracy() const;
    ushort          pp() const;
    QString         description() const;

private:
    const QString         m_name;
    const Category        m_category;
    const TypeInfo::Type  m_type;
    const ushort          m_power;
    const ushort          m_accuracy;
    const ushort          m_pp;
    const QString         m_description;
};

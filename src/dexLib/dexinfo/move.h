#pragma once

// Qt headers
#include <QtGlobal>
#include <QString>

// library headers
#include "dexlib_export.h"
#include "info.h"

class DEXLIB_EXPORT Move{

public:
    enum class Category
    {
        Physical = 0,
        Special,
        NonDamaging,
        Unknown
    };

    explicit Move(const QString         &name,
                  const Category        &category,
                  const Info::Type      &type,
                  const ushort          &power,
                  const ushort          &accuracy,
                  const ushort          &pp,
                  const QString         &description);
    Move(const Move &other) noexcept;
    ~Move();

    QString         name() const;
    Category        category() const;
    Info::Type      type() const;
    ushort          power() const;
    ushort          accuracy() const;
    ushort          pp() const;
    QString         description() const;

    static const QString categoryToString(const Category &category);
    static const Category stringToCategory(const QString & str);

private:
    const QString         m_name;
    const Category        m_category;
    const Info::Type      m_type;
    const ushort          m_power;
    const ushort          m_accuracy;
    const ushort          m_pp;
    const QString         m_description;
};

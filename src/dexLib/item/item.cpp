#include "item.h"

Item::Item(const ushort  &id,
           const QString &name,
           const Type    &type,
           const QString &description):
    m_id(id),
    m_name(name),
    m_type(type),
    m_description(description)
{

}

Item::Item(const Item &other) noexcept:
    Item(other.m_id,
         other.m_name,
         other.m_type,
         other.m_description)
{

}

Item::~Item()
{

}

ushort Item::id() const
{
    return m_id;
}

QString Item::name() const
{
    return m_name;
}

Item::Type Item::type() const
{
    return m_type;
}

QString Item::description() const
{
    return m_description;
}

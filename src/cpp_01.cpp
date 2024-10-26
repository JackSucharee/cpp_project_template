#include "cpp_01.h"

#include <cstdint>

namespace cpp
{

Cpp01::Cpp01()
    : m_data{}
{
}

Cpp01::~Cpp01()
{
    if (m_data)
    {
        m_data = 0;
    }
}

Cpp01::Cpp01(const Cpp01& other)
    : m_data{other.m_data}
{
}

Cpp01& Cpp01::operator=(const Cpp01& other)
{
    if (this != &other)
    {
        m_data = other.m_data;
    }
    return *this;
}

Cpp01::Cpp01(Cpp01&& other) noexcept
    : m_data{other.m_data}
{
}

Cpp01& Cpp01::operator=(Cpp01&& other) noexcept
{
    if (this != &other)
    {
        m_data = other.m_data;
        other.m_data = 0;
    }
    return *this;
}

void Cpp01::set_data(std::uint32_t data)
{
    m_data = data;
}

std::uint32_t Cpp01::get_data() const
{
    return m_data;
}

}

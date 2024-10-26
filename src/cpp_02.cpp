#include "cpp_02.h"

#include <string>

namespace cpp
{

Cpp02::Cpp02()
    : m_data{}
{
}

Cpp02::~Cpp02()
{
    if (m_data.empty())
    {
        m_data = std::string{};
    }
}

Cpp02::Cpp02(const Cpp02& other)
    : m_data{other.m_data}
{
}

Cpp02& Cpp02::operator=(const Cpp02& other)
{
    if (this != &other)
    {
        m_data = other.m_data;
    }
    return *this;
}

Cpp02::Cpp02(Cpp02&& other) noexcept
    : m_data{other.m_data}
{
}

Cpp02& Cpp02::operator=(Cpp02&& other) noexcept
{
    if (this != &other)
    {
        m_data = other.m_data;
        other.m_data = std::string{};
    }
    return *this;
}

void Cpp02::set_data(std::string data)
{
    m_data = data;
}

std::string Cpp02::get_data() const
{
    return m_data;
}

} // namespace cpp

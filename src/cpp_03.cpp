#include "cpp_03.h"

#include <cstddef>

namespace cpp
{

void Cpp03::set_data(std::vector<std::size_t> data)
{
    m_data = data;
}

std::vector<std::size_t> Cpp03::get_data() const
{
    return m_data;
}

} // namespace cpp

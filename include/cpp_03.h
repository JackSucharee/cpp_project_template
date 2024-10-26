#pragma once

#include <cstddef>
#include <vector>

namespace cpp
{

class Cpp03
{
public:
    void set_data(std::vector<std::size_t> data);

    std::vector<std::size_t> get_data() const;

private:
    std::vector<std::size_t> m_data;
};

} // namespace cpp

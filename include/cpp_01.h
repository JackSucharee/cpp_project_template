#pragma once

#include <cstdint>

namespace cpp
{

class Cpp01
{
public:
    Cpp01();

    ~Cpp01();

    Cpp01(const Cpp01& other);

    Cpp01& operator=(const Cpp01& other);

    Cpp01(Cpp01&& other) noexcept;

    Cpp01& operator=(Cpp01&& other) noexcept;

    void set_data(std::uint32_t data);

    std::uint32_t get_data() const;

private:
    std::uint32_t m_data = 0;
};

} // namespace cpp

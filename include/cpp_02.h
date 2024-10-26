#pragma once

#include <string>

namespace cpp
{

class Cpp02
{
public:
    Cpp02();

    ~Cpp02();

    Cpp02(const Cpp02& other);

    Cpp02& operator=(const Cpp02& other);

    Cpp02(Cpp02&& other) noexcept;

    Cpp02& operator=(Cpp02&& other) noexcept;

    void set_data(std::string data);

    std::string get_data() const;

private:
    std::string m_data;
};

} // namespace cpp

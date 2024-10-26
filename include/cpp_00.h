#pragma once

namespace cpp
{

template <typename T>
class Cpp00
{
public:
    Cpp00()
        : m_data{}
    {
    }

    ~Cpp00()
    {
    }

    Cpp00(const Cpp00& other)
        : m_data{other.m_data}
    {
    }

    Cpp00& operator=(const Cpp00& other)
    {
        if (this != &other)
        {
            m_data = other.m_data;
        }
        return *this;
    }

    Cpp00(Cpp00&& other) noexcept
        : m_data{other.m_data}
    {
    }

    Cpp00& operator=(Cpp00&& other) noexcept
    {
        if (this != &other)
        {
            m_data = other.m_data;
            other.m_data = T{};
        }
        return *this;
    }

    void set_data(T data)
    {
        m_data = data;
    }

    T get_data() const
    {
        return m_data;
    }

private:
    T m_data{};
};

} // namespace cpp

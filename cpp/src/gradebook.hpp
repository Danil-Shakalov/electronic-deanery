#pragma once

#include <cstdint>
#include <string>

namespace deanery
{

class Gradebook
{
private:
    std::string m_number{};
    std::uint32_t m_currentSemester{ 1 };

public:
    Gradebook() = delete;
    explicit Gradebook(std::string number, std::uint32_t semester = 1);

    Gradebook(const Gradebook&)            = default;
    Gradebook(Gradebook&&)                 = default;
    Gradebook& operator=(const Gradebook&) = default;
    Gradebook& operator=(Gradebook&&)      = default;
    ~Gradebook()                           = default;

    [[nodiscard]] std::string GetNumber() const { return m_number; }
    [[nodiscard]] std::uint32_t GetSemester() const { return m_currentSemester; }

    void AdvanceSemester() { ++m_currentSemester; }
};

} // namespace deanery


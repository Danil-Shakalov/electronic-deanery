#include "course.hpp"
#include <iostream>

namespace deanery
{

Course::Course(std::string_view title, int maxSeats)
    : m_title{ title }
    , m_maxSeats{ maxSeats }
    , m_enrolledCount{ 0 }
{
}

Course::~Course()
{
    std::cout << "[Деструктор] Курс " << m_title << " уничтожен.\n";
}

void Course::EnrollStudent()
{
    if (HasFreeSeats()) {
        ++m_enrolledCount;
    }
}

} // namespace deanery

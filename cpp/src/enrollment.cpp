#include "enrollment.hpp"
#include <iostream>

namespace deanery
{

Enrollment::Enrollment(Student* student, Course* course)
    : m_student{ student }
    , m_course{ course }
{
}

Enrollment::~Enrollment()
{
    // При уничтожении агрегатора студент и курс не удаляются!
    std::cout << "[Деструктор] Запись на курс " << m_course->GetTitle() << " удалена.\n";
}

bool Enrollment::ProcessEnrollment()
{
    if (m_student->HasDebt()) {
        std::cout << "Отказ: Студент " << m_student->GetName() << " не может быть записан (есть задолженность).\n";
        return false;
    }
    
    if (!m_course->HasFreeSeats()) {
        std::cout << "Отказ: На курс " << m_course->GetTitle() << " нет свободных мест.\n";
        return false;
    }

    m_course->EnrollStudent();
    std::cout << "Успех: Студент " << m_student->GetName() << " записан на курс " << m_course->GetTitle() << ".\n";
    return true;
}

} // namespace deanery

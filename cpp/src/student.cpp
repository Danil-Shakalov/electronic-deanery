#include "student.hpp"
#include <iostream>

namespace deanery
{

Student::Student(std::uint64_t id, std::string_view name, std::string gradebookNum, bool hasDebt)
    : m_id{ id }
    , m_fullName{ name }
    , m_hasDebt{ hasDebt }
    , m_gradebook{ std::move(gradebookNum), 1 } // Часть создается вместе с целым
{
}

Student::~Student()
{
    std::cout << "[Деструктор] Студент " << m_fullName << " уничтожен.\n";
}

void Student::TransferToNextCourse()
{
    if (m_hasDebt) {
        std::cout << "Отказ: Студент " << m_fullName << " имеет задолженность, перевод невозможен.\n";
        return;
    }
    m_gradebook.AdvanceSemester();
    std::cout << "Студент " << m_fullName << " переведен. Текущий семестр: " << m_gradebook.GetSemester() << "\n";
}

} // namespace deanery

#pragma once

#include "student.hpp"
#include "course.hpp"

namespace deanery
{

class Enrollment
{
private:
    // Агрегация: используем указатели на объекты, созданные снаружи
    Student* m_student{ nullptr };
    Course* m_course{ nullptr };

public:
    Enrollment() = delete;
    Enrollment(Student* student, Course* course);
    
    ~Enrollment();

    // Содержательный метод, проверяющий правило из задания 2
    bool ProcessEnrollment();
    
    [[nodiscard]] Student* GetStudent() const { return m_student; }
    [[nodiscard]] Course* GetCourse() const { return m_course; }
};

} // namespace deanery

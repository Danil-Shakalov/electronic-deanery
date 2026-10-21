#pragma once

#include "gradebook.hpp"
#include <string>
#include <string_view>

namespace deanery
{

class Student
{
private:
    std::uint64_t m_id{};
    std::string m_fullName{};
    bool m_hasDebt{ false };
    
    // Композиция: Зачетка создается и умирает вместе со студентом
    Gradebook m_gradebook;

public:
    Student() = delete;
    Student(std::uint64_t id, std::string_view name, std::string gradebookNum, bool hasDebt = false);

    Student(const Student&)            = delete;
    Student(Student&&)                 = delete;
    Student& operator=(const Student&) = delete;
    Student& operator=(Student&&)      = delete;
    
    // Деструктор для вывода в консоль
    ~Student();

    [[nodiscard]] std::uint64_t GetId() const { return m_id; }
    [[nodiscard]] std::string_view GetName() const { return m_fullName; }
    [[nodiscard]] bool HasDebt() const { return m_hasDebt; }

    // Содержательный метод: перевод на следующий курс
    void TransferToNextCourse();
    
    // Доступ к части (композиции)
    [[nodiscard]] const Gradebook& GetGradebook() const { return m_gradebook; }
};

} // namespace deanery

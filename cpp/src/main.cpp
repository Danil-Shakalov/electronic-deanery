#include "student.hpp"
#include "course.hpp"
#include "enrollment.hpp"
#include <iostream>

using namespace deanery; // Используем только в .cpp, как требует code style

int main()
{
    std::cout << "=== Демонстрация работы классов ===\n\n";

    // 1. Демонстрация АГРЕГАЦИИ и времени жизни
    std::cout << "--- Блок 1: Агрегация ---\n";
    {
        Student* s1 = new Student(101, "Иванов И.И.", "ГБ-101", false);
        Course* c1 = new Course("Программирование", 2);

        std::cout << "--- Блок 1.1: Создание агрегатора ---\n";
        {
            Enrollment* e1 = new Enrollment(s1, c1);
            e1->ProcessEnrollment(); // Успех
            
            std::cout << "--- Блок 1.2: Удаление агрегатора ---\n";
            delete e1; // Удаляется только запись, студент и курс остаются!
        }

        std::cout << "--- Блок 1.3: Проверка, что агрегируемые объекты живы ---\n";
        std::cout << "Студент " << s1->GetName() << " всё ещё существует. Его зачетка: " << s1->GetGradebook().GetNumber() << "\n";
        
        delete c1;
        delete s1;
    }
    std::cout << "\n";

    // 2. Демонстрация КОМПОЗИЦИИ и времени жизни
    std::cout << "--- Блок 2: Композиция ---\n";
    {
        std::cout << "--- Блок 2.1: Создание целого (Студента) ---\n";
        Student s2(102, "Петров П.П.", "ГБ-102", false);
        
        std::cout << "Зачетка студента (номер): " << s2.GetGradebook().GetNumber() << "\n";
        
        std::cout << "--- Блок 2.2: Попытка перевода на след. курс ---\n";
        s2.TransferToNextCourse();

        std::cout << "--- Блок 2.3: Конец блока (выход из скоупа) ---\n";
    }
    std::cout << "\n";

    // 3. Демонстрация проверки правил и массивов
    std::cout << "--- Блок 3: Проверка правил и массивы ---\n";
    {
        Student** students = new Student*[2];
        students[0] = new Student(201, "Сидоров С.С.", "ГБ-201", true); // Должник
        students[1] = new Student(202, "Смирнов С.С.", "ГБ-202", false); // Обычный

                Course* c2 = new Course("Базы данных", 1);

        // Оборачиваем Enrollment в отдельный блок, чтобы они удалились до очистки памяти
        {
            // Попытка записать должника
            Enrollment e2(students[0], c2);
            e2.ProcessEnrollment(); // Должен быть отказ

            // Запись обычного студента
            Enrollment e3(students[1], c2);
            e3.ProcessEnrollment(); // Успех

            // Попытка записать еще одного на тот же курс (мест нет)
            Enrollment e4(students[1], c2);
            e4.ProcessEnrollment(); // Отказ (нет мест)
        } // <--- ЗДЕСЬ Enrollment (e2, e3, e4) уничтожаются, и память c2 еще цела

        // Динамический массив объектов
        Course** cArr = new Course*[2] { new Course("История", 10), new Course("Философия", 20) };
        std::cout << "Второй курс в массиве: " << cArr[1]->GetTitle() << "\n";

        delete cArr[0];
        delete cArr[1];
        delete[] cArr;
        
        // Теперь безопасно удаляем c2 и студентов
        delete c2;
        delete students[0];
        delete students[1];
        delete[] students;
    }

    return 0;
}

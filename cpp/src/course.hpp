#pragma once

#include <string>
#include <string_view>

namespace deanery
{

class Course
{
private:
    std::string m_title{};
    int m_maxSeats{ 0 };
    int m_enrolledCount{ 0 };

public:
    Course() = delete;
    Course(std::string_view title, int maxSeats);

    Course(const Course&)            = default;
    Course(Course&&)                 = default;
    Course& operator=(const Course&) = default;
    Course& operator=(Course&&)      = default;

    ~Course();

    [[nodiscard]] std::string_view GetTitle() const { return m_title; }
    [[nodiscard]] int GetMaxSeats() const { return m_maxSeats; }
    [[nodiscard]] int GetEnrolledCount() const { return m_enrolledCount; }

    bool HasFreeSeats() const { return m_enrolledCount < m_maxSeats; }
    
    void EnrollStudent();
};

} // namespace deanery

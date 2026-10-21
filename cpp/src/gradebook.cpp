#include "gradebook.hpp"

namespace deanery
{

Gradebook::Gradebook(std::string number, std::uint32_t semester)
    : m_number{ number }
    , m_currentSemester{ semester }
{
}

} // namespace deanery

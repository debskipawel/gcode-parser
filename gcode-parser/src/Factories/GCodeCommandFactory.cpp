#include "GCodeCommandFactory.h"

namespace GCP
{
    bool GCodeCommandFactory::CanBeCreatedFrom(std::string codeLine)
    {
        return std::regex_match(codeLine, m_CommandValidationRegex);
    }
}

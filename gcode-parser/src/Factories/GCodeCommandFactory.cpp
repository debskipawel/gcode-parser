#include "GCodeCommandFactory.h"



namespace GCP
{
    bool GCodeCommandFactory::CanBeCreatedFrom(std::string codeLine)
    {
        return std::any_of(m_CommandValidationRegexes.begin(), m_CommandValidationRegexes.end(),
            [&codeLine](const std::regex& validationRegex) 
            { 
                auto match = std::regex_match(codeLine, validationRegex); 
                return match;
            }
        );
    }
}

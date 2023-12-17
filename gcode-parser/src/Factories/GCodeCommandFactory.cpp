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

    auto GCodeCommandFactory::LineNumber(std::string codeLine) -> unsigned int
    {
        std::smatch match;

        if (std::regex_search(codeLine, match, std::regex("^\\s*N([0-9]+)")))
        {
            auto value = match[1].str();

            return std::stoi(value);
        }

        return 0;
    }
}

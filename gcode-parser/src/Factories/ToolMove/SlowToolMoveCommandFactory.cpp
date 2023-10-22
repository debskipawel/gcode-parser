#include "SlowToolMoveCommandFactory.h"

#include <Commands/ToolMove/SlowToolMoveCommand.h>
#include <Factories/GCodeRegexResources.h>

namespace GCP
{
    SlowToolMoveCommandFactory::SlowToolMoveCommandFactory()
    {
        m_CommandValidationRegexes.emplace_back(
            std::format(
                "^{}\\s*(G0*1)\\s*({})?\\s*({})?\\s*({})?\\s*({})?\\s*$",
                GCodeRegexResources::s_LineNumberPrefix,
                m_RegexNumericValueF,
                m_RegexNumericValueX,
                m_RegexNumericValueY,
                m_RegexNumericValueZ
            )
        );
    }

    std::shared_ptr<GCodeCommand> SlowToolMoveCommandFactory::CreateCommand(std::optional<float> x, std::optional<float> y, std::optional<float> z, std::optional<float> speed)
    {
        return std::make_shared<SlowToolMoveCommand>(x, y, z, speed);
    }
}

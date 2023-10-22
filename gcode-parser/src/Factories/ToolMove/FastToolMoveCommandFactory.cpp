#include "FastToolMoveCommandFactory.h"

#include <Commands/ToolMove/FastToolMoveCommand.h>
#include <Factories/GCodeRegexResources.h>

namespace GCP
{
	FastToolMoveCommandFactory::FastToolMoveCommandFactory()
	{
		m_CommandValidationRegexes.emplace_back(
			std::format(
				"^{}\\s*(G0+)\\s*({})?\\s*({})?\\s*({})?\\s*({})?\\s*$",
				GCodeRegexResources::s_LineNumberPrefix,
				m_RegexNumericValueF,
				m_RegexNumericValueX,
				m_RegexNumericValueY,
				m_RegexNumericValueZ
			)
		);
	}

	std::shared_ptr<GCodeCommand> FastToolMoveCommandFactory::CreateCommand(std::optional<float> x, std::optional<float> y, std::optional<float> z, std::optional<float> speed)
	{
		return std::make_shared<FastToolMoveCommand>(x, y, z, speed);
	}
}

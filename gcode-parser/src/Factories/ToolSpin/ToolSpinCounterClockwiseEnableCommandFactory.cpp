#include "ToolSpinCounterClockwiseEnableCommandFactory.h"

#include <Commands/ToolSpin/ToolSpinCounterClockwiseEnableCommand.h>
#include <Factories/GCodeRegexResources.h>

namespace GCP
{
	ToolSpinCounterClockwiseEnableCommandFactory::ToolSpinCounterClockwiseEnableCommandFactory()
	{
		m_CommandValidationRegexes.emplace_back(
			std::format(
				"^{}\\s*(M0*4)\\s*({})?\\s*($|((M|G).*$))",
				GCodeRegexResources::s_LineNumberPrefix,
				m_RegexNumericValueRotationSpeed
			)
		);
	}

	std::shared_ptr<GCodeCommand> ToolSpinCounterClockwiseEnableCommandFactory::CreateCommand(unsigned int lineNumber, std::optional<float> rotationSpeed)
	{
		return rotationSpeed.has_value()
			? std::make_shared<ToolSpinCounterClockwiseEnableCommand>(lineNumber, rotationSpeed.value())
			: std::make_shared<ToolSpinCounterClockwiseEnableCommand>(lineNumber);
	}
}

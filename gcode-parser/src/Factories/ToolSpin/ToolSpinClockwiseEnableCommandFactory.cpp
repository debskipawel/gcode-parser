#include "ToolSpinClockwiseEnableCommandFactory.h"

#include <Commands/ToolSpin/ToolSpinClockwiseEnableCommand.h>
#include <Factories/GCodeRegexResources.h>

namespace GCP
{
	ToolSpinClockwiseEnableCommandFactory::ToolSpinClockwiseEnableCommandFactory()
		: ToolSpinEnableCommandFactory()
	{
		m_CommandValidationRegexes.emplace_back( 
			std::format(
				"^{}\\s*(M0*3)\\s*({})?\\s*($|((M|G).*$))",
				GCodeRegexResources::s_LineNumberPrefix,
				m_RegexNumericValueRotationSpeed
			)
		);
	}

	std::shared_ptr<GCodeCommand> ToolSpinClockwiseEnableCommandFactory::CreateCommand(unsigned int lineNumber, std::optional<float> rotationSpeed)
	{
		return rotationSpeed.has_value()
			? std::make_shared<ToolSpinClockwiseEnableCommand>(lineNumber, rotationSpeed.value())
			: std::make_shared<ToolSpinClockwiseEnableCommand>(lineNumber);
	}
}

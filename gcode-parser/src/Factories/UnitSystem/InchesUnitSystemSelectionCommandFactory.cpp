#include "InchesUnitSystemSelectionCommandFactory.h"

#include <Commands/UnitSystem/InchesUnitSystemSelectionCommand.h>
#include <Factories/GCodeRegexResources.h>

namespace GCP
{
	InchesUnitSystemSelectionCommandFactory::InchesUnitSystemSelectionCommandFactory()
	{
		m_CommandValidationRegexes.emplace_back(
			std::format(
				"{}\\s*G(0*)20\\s*(G|M)",
				GCodeRegexResources::s_LineNumberPrefix
			)
		);
	}

	std::shared_ptr<GCodeCommand> InchesUnitSystemSelectionCommandFactory::CreateFrom(std::string codeLine)
	{
		return std::make_shared<InchesUnitSystemSelectionCommand>();
	}
}

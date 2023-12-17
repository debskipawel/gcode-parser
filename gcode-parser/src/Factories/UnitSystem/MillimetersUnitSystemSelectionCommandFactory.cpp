#include "MillimetersUnitSystemSelectionCommandFactory.h"

#include <Commands/UnitSystem/MillimetersUnitSystemSelectionCommand.h>
#include <Factories/GCodeRegexResources.h>

namespace GCP
{
	GCP::MillimetersUnitSystemSelectionCommandFactory::MillimetersUnitSystemSelectionCommandFactory()
	{
		m_CommandValidationRegexes.emplace_back(
			std::format(
				"{}\\s*G21\\s*",
				GCodeRegexResources::s_LineNumberPrefix
			)
		);
	}

	std::shared_ptr<GCodeCommand> GCP::MillimetersUnitSystemSelectionCommandFactory::CreateFrom(std::string codeLine)
	{
		auto lineNumber = LineNumber(codeLine);

		return std::make_shared<MillimetersUnitSystemSelectionCommand>(lineNumber);
	}
}

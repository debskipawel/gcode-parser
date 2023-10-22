#include "ProgramStopCommandFactory.h"

#include <Commands/ProgramStop/ProgramStopCommand.h>
#include <Factories/GCodeRegexResources.h>

namespace GCP
{
	ProgramStopCommandFactory::ProgramStopCommandFactory()
	{
		m_CommandValidationRegexes.emplace_back(
			std::format(
				"{}.*M(0*)30\\s*($|((M|G).*$))",
				GCodeRegexResources::s_LineNumberPrefix
			)
		);
	}

	std::shared_ptr<GCodeCommand> ProgramStopCommandFactory::CreateFrom(std::string codeLine)
	{
		return std::make_shared<ProgramStopCommand>();
	}
}

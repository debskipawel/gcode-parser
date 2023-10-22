#include "CutterCompensationDisableCommandFactory.h"

#include <Commands/CutterCompensation/CutterCompensationDisableCommand.h>
#include <Factories/GCodeRegexResources.h>

namespace GCP
{
	CutterCompensationDisableCommandFactory::CutterCompensationDisableCommandFactory()
	{
		m_CommandValidationRegexes.emplace_back(
			std::format("^{}.*G(0*)40\\s*($|((M|G).*$))", GCodeRegexResources::s_LineNumberPrefix)
		);
	}

	std::shared_ptr<GCodeCommand> CutterCompensationDisableCommandFactory::CreateFrom(std::string codeLine)
	{
		return std::make_shared<CutterCompensationDisableCommand>();
	}
}

#include "ToolSpinDisableCommandFactory.h"

#include <Commands/ToolSpin/ToolSpinDisableCommand.h>
#include <Factories/GCodeRegexResources.h>

namespace GCP
{
	ToolSpinDisableCommandFactory::ToolSpinDisableCommandFactory()
	{
		m_CommandValidationRegexes.emplace_back(std::format("^{}.*M0*5\\s*($|((M|G).*$))", GCodeRegexResources::s_LineNumberPrefix));
	}

	std::shared_ptr<GCodeCommand> ToolSpinDisableCommandFactory::CreateFrom(std::string codeLine)
	{
		return std::make_shared<ToolSpinDisableCommand>();
	}
}

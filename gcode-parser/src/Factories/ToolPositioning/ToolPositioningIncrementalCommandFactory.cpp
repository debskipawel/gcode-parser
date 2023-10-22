#include "ToolPositioningIncrementalCommandFactory.h"

#include <Commands/ToolPositioning/ToolPositioningIncrementalCommand.h>
#include <Factories/GCodeRegexResources.h>

namespace GCP
{
	ToolPositioningIncrementalCommandFactory::ToolPositioningIncrementalCommandFactory()
	{
		m_CommandValidationRegexes.emplace_back(
			std::format(
				"{}.*G(0*)91\\s*($|((M|G).*$))",
				GCodeRegexResources::s_LineNumberPrefix
			)
		);
	}

	std::shared_ptr<GCodeCommand> ToolPositioningIncrementalCommandFactory::CreateFrom(std::string codeLine)
	{
		return std::make_shared<ToolPositioningIncrementalCommand>();
	}
}

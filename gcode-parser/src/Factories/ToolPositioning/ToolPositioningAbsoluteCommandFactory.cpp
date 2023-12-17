#include "ToolPositioningAbsoluteCommandFactory.h"

#include <Commands/ToolPositioning/ToolPositioningAbsoluteCommand.h>
#include <Factories/GCodeRegexResources.h>

namespace GCP
{
	ToolPositioningAbsoluteCommandFactory::ToolPositioningAbsoluteCommandFactory()
	{
		m_CommandValidationRegexes.emplace_back(
			std::format(
				"{}.*G(0*)90\\s*($|((M|G).*$))",
				GCodeRegexResources::s_LineNumberPrefix
			)
		);
	}

	std::shared_ptr<GCodeCommand> ToolPositioningAbsoluteCommandFactory::CreateFrom(std::string codeLine)
	{
		auto lineNumber = LineNumber(codeLine);

		return std::make_shared<ToolPositioningAbsoluteCommand>(lineNumber);
	}
}

#include "ToolPositioningAbsoluteCommand.h"

#include <Visitors/GCodeCommandVisitor.h>

namespace GCP
{
	ToolPositioningAbsoluteCommand::ToolPositioningAbsoluteCommand(unsigned int lineNumber)
		: GCodeCommand(lineNumber)
	{
	}

	void ToolPositioningAbsoluteCommand::Accept(GCodeCommandVisitor& visitor)
	{
		visitor.Visit(*this);
	}
}

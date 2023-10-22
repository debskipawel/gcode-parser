#include "ToolPositioningAbsoluteCommand.h"

#include <Visitors/GCodeCommandVisitor.h>

namespace GCP
{
	ToolPositioningAbsoluteCommand::ToolPositioningAbsoluteCommand()
	{
	}

	void ToolPositioningAbsoluteCommand::Accept(GCodeCommandVisitor& visitor)
	{
		visitor.Visit(*this);
	}
}

#include "ToolPositioningIncrementalCommand.h"

#include <Visitors/GCodeCommandVisitor.h>

namespace GCP
{
	ToolPositioningIncrementalCommand::ToolPositioningIncrementalCommand(unsigned int lineNumber)
		: GCodeCommand(lineNumber)
	{
	}

	void ToolPositioningIncrementalCommand::Accept(GCodeCommandVisitor& visitor)
	{
		visitor.Visit(*this);
	}
}

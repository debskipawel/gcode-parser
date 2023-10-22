#include "ToolPositioningIncrementalCommand.h"

#include <Visitors/GCodeCommandVisitor.h>

namespace GCP
{
	ToolPositioningIncrementalCommand::ToolPositioningIncrementalCommand()
	{
	}

	void ToolPositioningIncrementalCommand::Accept(GCodeCommandVisitor& visitor)
	{
		visitor.Visit(*this);
	}
}

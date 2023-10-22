#include "ToolSpinCounterClockwiseEnableCommand.h"

#include <Visitors/GCodeCommandVisitor.h>

namespace GCP
{
	ToolSpinCounterClockwiseEnableCommand::ToolSpinCounterClockwiseEnableCommand()
		: ToolSpinEnableCommand()
	{
	}

	ToolSpinCounterClockwiseEnableCommand::ToolSpinCounterClockwiseEnableCommand(float rotationSpeed)
		: ToolSpinEnableCommand(rotationSpeed)
	{
	}

	void ToolSpinCounterClockwiseEnableCommand::Accept(GCodeCommandVisitor& visitor)
	{
		visitor.Visit(*this);
	}
}

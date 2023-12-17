#include "ToolSpinCounterClockwiseEnableCommand.h"

#include <Visitors/GCodeCommandVisitor.h>

namespace GCP
{
	ToolSpinCounterClockwiseEnableCommand::ToolSpinCounterClockwiseEnableCommand(unsigned int lineNumber)
		: ToolSpinEnableCommand(lineNumber)
	{
	}

	ToolSpinCounterClockwiseEnableCommand::ToolSpinCounterClockwiseEnableCommand(unsigned int lineNumber, float rotationSpeed)
		: ToolSpinEnableCommand(lineNumber, rotationSpeed)
	{
	}

	void ToolSpinCounterClockwiseEnableCommand::Accept(GCodeCommandVisitor& visitor)
	{
		visitor.Visit(*this);
	}
}

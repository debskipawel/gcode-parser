#include "ToolSpinClockwiseEnableCommand.h"

#include <Visitors/GCodeCommandVisitor.h>

namespace GCP
{
	ToolSpinClockwiseEnableCommand::ToolSpinClockwiseEnableCommand(unsigned int lineNumber)
		: ToolSpinEnableCommand(lineNumber)
	{
	}

	ToolSpinClockwiseEnableCommand::ToolSpinClockwiseEnableCommand(unsigned int lineNumber, float rotationSpeed)
		: ToolSpinEnableCommand(lineNumber, rotationSpeed)
	{
	}
	
	void ToolSpinClockwiseEnableCommand::Accept(GCodeCommandVisitor& visitor)
	{
		visitor.Visit(*this);
	}
}

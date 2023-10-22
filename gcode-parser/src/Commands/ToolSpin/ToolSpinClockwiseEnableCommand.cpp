#include "ToolSpinClockwiseEnableCommand.h"

#include <Visitors/GCodeCommandVisitor.h>

namespace GCP
{
	ToolSpinClockwiseEnableCommand::ToolSpinClockwiseEnableCommand()
		: ToolSpinEnableCommand()
	{
	}

	ToolSpinClockwiseEnableCommand::ToolSpinClockwiseEnableCommand(float rotationSpeed)
		: ToolSpinEnableCommand(rotationSpeed)
	{
	}
	
	void ToolSpinClockwiseEnableCommand::Accept(GCodeCommandVisitor& visitor)
	{
		visitor.Visit(*this);
	}
}

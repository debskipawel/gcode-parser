#include "ToolSpinDisableCommand.h"

#include <Visitors/GCodeCommandVisitor.h>

namespace GCP
{
	ToolSpinDisableCommand::ToolSpinDisableCommand(unsigned int lineNumber)
		: GCodeCommand(lineNumber)
	{
	}

	void ToolSpinDisableCommand::Accept(GCodeCommandVisitor& visitor)
	{
		visitor.Visit(*this);
	}
}

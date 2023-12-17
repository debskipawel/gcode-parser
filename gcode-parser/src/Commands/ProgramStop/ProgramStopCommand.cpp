#include "ProgramStopCommand.h"

#include <Visitors/GCodeCommandVisitor.h>

namespace GCP
{
	ProgramStopCommand::ProgramStopCommand(unsigned int lineNumber)
		: GCodeCommand(lineNumber)
	{
	}

	void ProgramStopCommand::Accept(GCodeCommandVisitor& visitor)
	{
		visitor.Visit(*this);
	}
}

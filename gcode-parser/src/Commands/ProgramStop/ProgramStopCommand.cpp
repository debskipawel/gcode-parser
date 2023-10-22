#include "ProgramStopCommand.h"

#include <Visitors/GCodeCommandVisitor.h>

namespace GCP
{
	ProgramStopCommand::ProgramStopCommand()
	{
	}

	void ProgramStopCommand::Accept(GCodeCommandVisitor& visitor)
	{
		visitor.Visit(*this);
	}
}

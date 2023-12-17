#include "CutterCompensationDisableCommand.h"

#include <Visitors/GCodeCommandVisitor.h>

namespace GCP
{
	CutterCompensationDisableCommand::CutterCompensationDisableCommand(unsigned int lineNumber)
		: GCodeCommand(lineNumber)
	{
	}

	void CutterCompensationDisableCommand::Accept(GCodeCommandVisitor& visitor)
	{
		visitor.Visit(*this);
	}
}

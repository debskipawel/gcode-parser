#include "ToolSpinDisableCommand.h"

#include <Visitors/GCodeCommandVisitor.h>

namespace GCP
{
	void ToolSpinDisableCommand::Accept(GCodeCommandVisitor& visitor)
	{
		visitor.Visit(*this);
	}
}

#include "CutterCompensationDisableCommand.h"

#include <Visitors/GCodeCommandVisitor.h>

namespace GCP
{
	void CutterCompensationDisableCommand::Accept(GCodeCommandVisitor& visitor)
	{
		visitor.Visit(*this);
	}
}

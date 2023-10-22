#include "SlowToolMoveCommand.h"

#include <Visitors/GCodeCommandVisitor.h>

namespace GCP
{
	SlowToolMoveCommand::SlowToolMoveCommand(std::optional<float> x, std::optional<float> y, std::optional<float> z, std::optional<float> speed)
		: ToolMoveCommand(x, y, z, speed)
	{
	}

	void SlowToolMoveCommand::Accept(GCodeCommandVisitor& visitor)
	{
		visitor.Visit(*this);
	}
}

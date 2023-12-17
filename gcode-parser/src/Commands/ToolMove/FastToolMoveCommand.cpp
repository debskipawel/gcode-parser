#include "FastToolMoveCommand.h"

#include <Visitors/GCodeCommandVisitor.h>

namespace GCP
{
	FastToolMoveCommand::FastToolMoveCommand(unsigned int lineNumber, std::optional<float> x, std::optional<float> y, std::optional<float> z, std::optional<float> speed)
		: ToolMoveCommand(lineNumber, x, y, z, speed)
	{
	}

	void FastToolMoveCommand::Accept(GCodeCommandVisitor& visitor)
	{
		visitor.Visit(*this);
	}
}

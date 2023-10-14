#include "ToolMoveCommand.h"

#include <Visitors/GCodeCommandVisitor.h>

namespace GCP
{
	ToolMoveCommand::ToolMoveCommand(std::optional<float> x, std::optional<float> y, std::optional<float> z)
		: m_X(x), m_Y(y), m_Z(z)
	{
	}

	void ToolMoveCommand::Accept(GCodeCommandVisitor& visitor)
	{
		visitor.Visit(*this);
	}
}

#include "ToolMoveCommand.h"

#include <Visitors/GCodeCommandVisitor.h>

namespace GCP
{
	ToolMoveCommand::ToolMoveCommand(std::optional<float> x, std::optional<float> y, std::optional<float> z, std::optional<float> speed)
		: m_X(x), m_Y(y), m_Z(z), m_MoveSpeed(speed)
	{
	}
}

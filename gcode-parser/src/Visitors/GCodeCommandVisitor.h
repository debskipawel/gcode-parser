#pragma once

#include <Commands/ToolMove/ToolMoveCommand.h>

namespace GCP
{
	class GCodeCommandVisitor
	{
	public:
		virtual void Visit(GCodeCommand& command);

		virtual void Visit(ToolMoveCommand& command) = 0;
	};
}

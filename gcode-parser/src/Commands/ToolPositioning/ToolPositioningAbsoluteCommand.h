#pragma once

#include <Commands/GCodeCommand.h>

namespace GCP
{
	class ToolPositioningAbsoluteCommand : public GCodeCommand
	{
	public:
		explicit ToolPositioningAbsoluteCommand(unsigned int lineNumber = 0);

		virtual void Accept(GCodeCommandVisitor& visitor) override;
	};
}

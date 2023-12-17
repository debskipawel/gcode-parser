#pragma once

#include <Commands/GCodeCommand.h>

namespace GCP
{
	class ToolPositioningIncrementalCommand : public GCodeCommand
	{
	public:
		explicit ToolPositioningIncrementalCommand(unsigned int lineNumber = 0);

		virtual void Accept(GCodeCommandVisitor& visitor) override;
	};
}

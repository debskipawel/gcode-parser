#pragma once

#include <Commands/GCodeCommand.h>

namespace GCP
{
	class ToolPositioningIncrementalCommand : public GCodeCommand
	{
	public:
		explicit ToolPositioningIncrementalCommand();

		virtual void Accept(GCodeCommandVisitor& visitor) override;
	};
}

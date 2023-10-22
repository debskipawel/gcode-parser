#pragma once

#include <Commands/GCodeCommand.h>

namespace GCP
{
	class ToolPositioningAbsoluteCommand : public GCodeCommand
	{
	public:
		explicit ToolPositioningAbsoluteCommand();

		virtual void Accept(GCodeCommandVisitor& visitor) override;
	};
}

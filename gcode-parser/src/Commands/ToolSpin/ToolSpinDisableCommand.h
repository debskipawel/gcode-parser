#pragma once

#include <Commands/GCodeCommand.h>

namespace GCP
{
	class ToolSpinDisableCommand : public GCodeCommand
	{
	public:
		virtual void Accept(GCodeCommandVisitor& visitor) override;
	};
}

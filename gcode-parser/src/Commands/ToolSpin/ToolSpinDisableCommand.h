#pragma once

#include <Commands/GCodeCommand.h>

namespace GCP
{
	class ToolSpinDisableCommand : public GCodeCommand
	{
	public:
		ToolSpinDisableCommand(unsigned int lineNumber = 0);

		virtual void Accept(GCodeCommandVisitor& visitor) override;
	};
}

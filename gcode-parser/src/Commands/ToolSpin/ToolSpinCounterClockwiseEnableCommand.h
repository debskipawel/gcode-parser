#pragma once

#include <Commands/ToolSpin/ToolSpinEnableCommand.h>

namespace GCP
{
	class ToolSpinCounterClockwiseEnableCommand : public ToolSpinEnableCommand
	{
	public:
		explicit ToolSpinCounterClockwiseEnableCommand(unsigned int lineNumber = 0);
		explicit ToolSpinCounterClockwiseEnableCommand(unsigned int lineNumber, float rotationSpeed);

		virtual void Accept(GCodeCommandVisitor& visitor) override;
	};
}

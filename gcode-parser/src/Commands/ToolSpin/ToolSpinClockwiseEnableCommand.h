#pragma once

#include <Commands/ToolSpin/ToolSpinEnableCommand.h>

namespace GCP
{
	class ToolSpinClockwiseEnableCommand : public ToolSpinEnableCommand
	{
	public:
		explicit ToolSpinClockwiseEnableCommand(unsigned int lineNumber = 0);
		explicit ToolSpinClockwiseEnableCommand(unsigned int lineNumber, float rotationSpeed);

		virtual void Accept(GCodeCommandVisitor& visitor) override;
	};
}

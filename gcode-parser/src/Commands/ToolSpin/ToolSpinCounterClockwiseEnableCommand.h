#pragma once

#include <Commands/ToolSpin/ToolSpinEnableCommand.h>

namespace GCP
{
	class ToolSpinCounterClockwiseEnableCommand : public ToolSpinEnableCommand
	{
	public:
		explicit ToolSpinCounterClockwiseEnableCommand();
		explicit ToolSpinCounterClockwiseEnableCommand(float rotationSpeed);

		virtual void Accept(GCodeCommandVisitor& visitor) override;
	};
}

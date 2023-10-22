#pragma once

#include <Commands/ToolSpin/ToolSpinEnableCommand.h>

namespace GCP
{
	class ToolSpinClockwiseEnableCommand : public ToolSpinEnableCommand
	{
	public:
		explicit ToolSpinClockwiseEnableCommand();
		explicit ToolSpinClockwiseEnableCommand(float rotationSpeed);

		virtual void Accept(GCodeCommandVisitor& visitor) override;
	};
}

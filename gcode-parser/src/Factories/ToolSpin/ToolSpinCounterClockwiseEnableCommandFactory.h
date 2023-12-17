#pragma once

#include <Factories/ToolSpin/ToolSpinEnableCommandFactory.h>

namespace GCP
{
	class ToolSpinCounterClockwiseEnableCommandFactory : public ToolSpinEnableCommandFactory
	{
	public:
		explicit ToolSpinCounterClockwiseEnableCommandFactory();

	protected:
		virtual std::shared_ptr<GCodeCommand> CreateCommand(unsigned int lineNumber, std::optional<float> rotationSpeed) override;
	};
}

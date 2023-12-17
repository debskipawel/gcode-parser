#pragma once

#include <Factories/ToolSpin/ToolSpinEnableCommandFactory.h>

namespace GCP
{
	class ToolSpinClockwiseEnableCommandFactory : public ToolSpinEnableCommandFactory
	{
	public:
		explicit ToolSpinClockwiseEnableCommandFactory();

	protected:
		virtual std::shared_ptr<GCodeCommand> CreateCommand(unsigned int lineNumber, std::optional<float> rotationSpeed) override;
	};
}

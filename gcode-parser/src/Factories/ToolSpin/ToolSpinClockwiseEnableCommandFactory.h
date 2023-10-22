#pragma once

#include <Factories/ToolSpin/ToolSpinEnableCommandFactory.h>

namespace GCP
{
	class ToolSpinClockwiseEnableCommandFactory : public ToolSpinEnableCommandFactory
	{
	public:
		explicit ToolSpinClockwiseEnableCommandFactory();

	protected:
		virtual std::shared_ptr<GCodeCommand> CreateCommand(std::optional<float> rotationSpeed) override;
	};
}

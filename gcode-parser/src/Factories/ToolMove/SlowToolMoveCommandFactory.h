#pragma once

#include <Factories/ToolMove/ToolMoveCommandFactory.h>

namespace GCP
{
	class SlowToolMoveCommandFactory : public ToolMoveCommandFactory
	{
	public:
		explicit SlowToolMoveCommandFactory();

	protected:
		virtual std::shared_ptr<GCodeCommand> CreateCommand(unsigned int lineNumber, std::optional<float> x, std::optional<float> y, std::optional<float> z, std::optional<float> speed) override;
	};
}

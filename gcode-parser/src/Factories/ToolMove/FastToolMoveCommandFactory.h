#pragma once

#include <Factories/ToolMove/ToolMoveCommandFactory.h>

namespace GCP
{
	class FastToolMoveCommandFactory : public ToolMoveCommandFactory
	{
	public:
		explicit FastToolMoveCommandFactory();

	protected:
		virtual std::shared_ptr<GCodeCommand> CreateCommand(unsigned int lineNumber, std::optional<float> x, std::optional<float> y, std::optional<float> z, std::optional<float> speed) override;
	};
}

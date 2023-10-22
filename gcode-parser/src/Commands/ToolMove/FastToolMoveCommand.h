#pragma once

#include <Commands/ToolMove/ToolMoveCommand.h>

namespace GCP
{
	class FastToolMoveCommand : public ToolMoveCommand
	{
	public:
		explicit FastToolMoveCommand(std::optional<float> x, std::optional<float> y, std::optional<float> z, std::optional<float> speed);

		virtual void Accept(GCodeCommandVisitor& visitor) override;
	};
}

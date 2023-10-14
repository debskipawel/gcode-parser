#pragma once

#include <optional>

#include <Commands/GCodeCommand.h>

namespace GCP
{
	class ToolMoveCommand : public GCodeCommand
	{
	public:
		explicit ToolMoveCommand(std::optional<float> x = std::nullopt, std::optional<float> y = std::nullopt, std::optional<float> z = std::nullopt);

		virtual void Accept(GCodeCommandVisitor& visitor) override;

	protected:

		std::optional<float> m_X, m_Y, m_Z;
	};
}
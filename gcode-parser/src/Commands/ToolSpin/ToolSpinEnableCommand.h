#pragma once

#include <optional>

#include <Commands/GCodeCommand.h>

namespace GCP
{
	class ToolSpinEnableCommand : public GCodeCommand
	{
	public:
		explicit ToolSpinEnableCommand();
		explicit ToolSpinEnableCommand(float rotationSpeed);

		std::optional<float> m_RotationSpeed;
	};
}

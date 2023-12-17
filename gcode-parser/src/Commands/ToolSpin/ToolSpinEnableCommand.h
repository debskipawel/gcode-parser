#pragma once

#include <optional>

#include <Commands/GCodeCommand.h>

namespace GCP
{
	class ToolSpinEnableCommand : public GCodeCommand
	{
	public:
		explicit ToolSpinEnableCommand(unsigned int lineNumber);
		explicit ToolSpinEnableCommand(unsigned int lineNumber, float rotationSpeed);

		std::optional<float> m_RotationSpeed;
	};
}

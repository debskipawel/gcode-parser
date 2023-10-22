#include "ToolSpinEnableCommand.h"

namespace GCP
{
	ToolSpinEnableCommand::ToolSpinEnableCommand()
		: m_RotationSpeed(std::nullopt)
	{
	}

	ToolSpinEnableCommand::ToolSpinEnableCommand(float rotationSpeed)
		: m_RotationSpeed(rotationSpeed)
	{
	}
}

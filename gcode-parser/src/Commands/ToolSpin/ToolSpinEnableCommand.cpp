#include "ToolSpinEnableCommand.h"

namespace GCP
{
	ToolSpinEnableCommand::ToolSpinEnableCommand(unsigned int lineNumber)
		: GCodeCommand(lineNumber), m_RotationSpeed(std::nullopt)
	{
	}

	ToolSpinEnableCommand::ToolSpinEnableCommand(unsigned int lineNumber, float rotationSpeed)
		: GCodeCommand(lineNumber), m_RotationSpeed(rotationSpeed)
	{
	}
}

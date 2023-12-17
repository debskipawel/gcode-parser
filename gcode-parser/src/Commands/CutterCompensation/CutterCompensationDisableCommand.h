#pragma once

#include <Commands/GCodeCommand.h>

namespace GCP
{
	class CutterCompensationDisableCommand : public GCodeCommand
	{
	public:
		CutterCompensationDisableCommand(unsigned int lineNumber = 0);

		virtual void Accept(GCodeCommandVisitor& visitor) override;
	};
}

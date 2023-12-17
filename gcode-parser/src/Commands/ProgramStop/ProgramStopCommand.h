#pragma once

#include <Commands/GCodeCommand.h>

namespace GCP
{
	class ProgramStopCommand : public GCodeCommand
	{
	public:
		ProgramStopCommand(unsigned int lineNumber = 0);

		virtual void Accept(GCodeCommandVisitor& visitor) override;
	};
}

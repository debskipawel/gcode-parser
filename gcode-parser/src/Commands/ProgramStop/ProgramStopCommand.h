#pragma once

#include <Commands/GCodeCommand.h>

namespace GCP
{
	class ProgramStopCommand : public GCodeCommand
	{
	public:
		ProgramStopCommand();

		virtual void Accept(GCodeCommandVisitor& visitor) override;
	};
}

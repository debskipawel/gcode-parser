#pragma once

#include <Commands/GCodeCommand.h>

namespace GCP
{
	class CutterCompensationDisableCommand : public GCodeCommand
	{
	public:
		virtual void Accept(GCodeCommandVisitor& visitor) override;
	};
}

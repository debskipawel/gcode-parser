#pragma once

#include <Commands/GCodeCommand.h>
#include <Commands/UnitSystem/GCodeUnitSystem.h>

namespace GCP
{
	class UnitSystemSelectionCommand : public GCodeCommand
	{
	public:
		explicit UnitSystemSelectionCommand(unsigned int lineNumber);

		virtual GCodeUnitSystem GetUnitSystemSelected() const = 0;

		virtual void Accept(GCodeCommandVisitor& visitor) = 0;
	};
}

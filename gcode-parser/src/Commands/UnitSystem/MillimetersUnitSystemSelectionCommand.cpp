#include "MillimetersUnitSystemSelectionCommand.h"

namespace GCP
{
	MillimetersUnitSystemSelectionCommand::MillimetersUnitSystemSelectionCommand(unsigned int lineNumber)
		: UnitSystemSelectionCommand(lineNumber)
	{
	}

	void MillimetersUnitSystemSelectionCommand::Accept(GCodeCommandVisitor& visitor)
	{
	}

	GCodeUnitSystem MillimetersUnitSystemSelectionCommand::GetUnitSystemSelected() const
	{
		return GCodeUnitSystem::MILLIMETER;
	}
}

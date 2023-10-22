#include "MillimetersUnitSystemSelectionCommand.h"

namespace GCP
{
	MillimetersUnitSystemSelectionCommand::MillimetersUnitSystemSelectionCommand()
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

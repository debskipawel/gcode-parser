#include "MillimetersUnitSystemSelectionCommand.h"

#include <Visitors/GCodeCommandVisitor.h>

namespace GCP
{
	MillimetersUnitSystemSelectionCommand::MillimetersUnitSystemSelectionCommand(unsigned int lineNumber)
		: UnitSystemSelectionCommand(lineNumber)
	{
	}

	void MillimetersUnitSystemSelectionCommand::Accept(GCodeCommandVisitor& visitor)
	{
		visitor.Visit(*this);
	}

	GCodeUnitSystem MillimetersUnitSystemSelectionCommand::GetUnitSystemSelected() const
	{
		return GCodeUnitSystem::MILLIMETER;
	}
}

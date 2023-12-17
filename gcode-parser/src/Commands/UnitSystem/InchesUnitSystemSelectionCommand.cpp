#include "InchesUnitSystemSelectionCommand.h"

#include <Visitors/GCodeCommandVisitor.h>
#include "InchesUnitSystemSelectionCommand.h"

namespace GCP
{
    InchesUnitSystemSelectionCommand::InchesUnitSystemSelectionCommand(unsigned int lineNumber)
        : UnitSystemSelectionCommand(lineNumber)
    {
    }

    void InchesUnitSystemSelectionCommand::Accept(GCodeCommandVisitor& visitor)
    {
        visitor.Visit(*this);
    }

    GCodeUnitSystem InchesUnitSystemSelectionCommand::GetUnitSystemSelected() const
    {
        return GCodeUnitSystem::INCHES;
    }
}

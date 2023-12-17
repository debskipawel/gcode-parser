#pragma once

#include <Commands/UnitSystem/UnitSystemSelectionCommand.h>

namespace GCP
{
	class MillimetersUnitSystemSelectionCommand : public UnitSystemSelectionCommand
	{
	public:
		explicit MillimetersUnitSystemSelectionCommand(unsigned int lineNumber = 0);

		virtual void Accept(GCodeCommandVisitor& visitor) override;

		virtual GCodeUnitSystem GetUnitSystemSelected() const override;
	};
}

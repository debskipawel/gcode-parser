#pragma once

#include <Commands/UnitSystem/UnitSystemSelectionCommand.h>

namespace GCP
{
	class InchesUnitSystemSelectionCommand : public UnitSystemSelectionCommand
	{
	public:
		explicit InchesUnitSystemSelectionCommand(unsigned int lineNumber = 0);

		virtual void Accept(GCodeCommandVisitor& visitor) override;
		
		virtual GCodeUnitSystem GetUnitSystemSelected() const override;
	};
}

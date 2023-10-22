#pragma once

#include <Commands/UnitSystem/UnitSystemSelectionCommand.h>

namespace GCP
{
	class MillimetersUnitSystemSelectionCommand : public UnitSystemSelectionCommand
	{
	public:
		explicit MillimetersUnitSystemSelectionCommand();

		virtual void Accept(GCodeCommandVisitor& visitor) override;

		virtual GCodeUnitSystem GetUnitSystemSelected() const override;
	};
}

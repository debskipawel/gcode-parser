#pragma once

#include <Commands/ToolMove/FastToolMoveCommand.h>
#include <Commands/ToolMove/SlowToolMoveCommand.h>

#include <Commands/ToolSpin/ToolSpinClockwiseEnableCommand.h>
#include <Commands/ToolSpin/ToolSpinCounterClockwiseEnableCommand.h>
#include <Commands/ToolSpin/ToolSpinDisableCommand.h>

#include <Commands/CutterCompensation/CutterCompensationDisableCommand.h>

#include <Commands/ProgramStop/ProgramStopCommand.h>

#include <Commands/UnitSystem/InchesUnitSystemSelectionCommand.h>
#include <Commands/UnitSystem/MillimetersUnitSystemSelectionCommand.h>

#include <Commands/ToolPositioning/ToolPositioningAbsoluteCommand.h>
#include <Commands/ToolPositioning/ToolPositioningIncrementalCommand.h>

namespace GCP
{
	class GCodeCommandVisitor
	{
	public:
		virtual void Visit(GCodeCommand& command);

		virtual void Visit(FastToolMoveCommand& command) {}
		virtual void Visit(SlowToolMoveCommand& command) {}

		virtual void Visit(ToolSpinClockwiseEnableCommand& command) {}
		virtual void Visit(ToolSpinCounterClockwiseEnableCommand& command) {}
		virtual void Visit(ToolSpinDisableCommand& command) {}

		virtual void Visit(CutterCompensationDisableCommand& command) {}

		virtual void Visit(InchesUnitSystemSelectionCommand& command) {}
		virtual void Visit(MillimetersUnitSystemSelectionCommand& command) {}

		virtual void Visit(ProgramStopCommand& command) {}

		virtual void Visit(ToolPositioningAbsoluteCommand& command) {}
		virtual void Visit(ToolPositioningIncrementalCommand& command) {}
	};
}

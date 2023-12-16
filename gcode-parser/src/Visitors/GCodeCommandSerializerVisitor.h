#pragma once

#include <fstream>

#include <Visitors/GCodeCommandVisitor.h>

namespace GCP
{
	class GCodeCommandSerializerVisitor : public GCodeCommandVisitor
	{
	public:
		GCodeCommandSerializerVisitor(std::ofstream& fileStream);

		virtual void Visit(FastToolMoveCommand& command) override;
		virtual void Visit(SlowToolMoveCommand& command) override;

		virtual void Visit(ToolSpinClockwiseEnableCommand& command) override;
		virtual void Visit(ToolSpinCounterClockwiseEnableCommand& command) override;
		virtual void Visit(ToolSpinDisableCommand& command) override;

		virtual void Visit(CutterCompensationDisableCommand& command) override;

		virtual void Visit(InchesUnitSystemSelectionCommand& command) override;
		virtual void Visit(MillimetersUnitSystemSelectionCommand& command) override;

		virtual void Visit(ProgramStopCommand& command) override;

		virtual void Visit(ToolPositioningAbsoluteCommand& command) override;
		virtual void Visit(ToolPositioningIncrementalCommand& command) override;

	protected:
		std::ofstream& m_FileStream;
	};
}

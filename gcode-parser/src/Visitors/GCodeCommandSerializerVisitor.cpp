#include "GCodeCommandSerializerVisitor.h"

#include <string>
#include <format>

namespace GCP
{
	GCodeCommandSerializerVisitor::GCodeCommandSerializerVisitor(std::ofstream& fileStream)
		: m_FileStream(fileStream)
	{
	}
	
	void GCodeCommandSerializerVisitor::Visit(FastToolMoveCommand& command)
	{
		auto moveSpeedText = command.m_MoveSpeed ? std::format("F{} ", command.m_MoveSpeed.value()) : "";
		auto moveXText = command.m_X ? std::format("X{} ", command.m_X.value()) : "";
		auto moveYText = command.m_Y ? std::format("Y{} ", command.m_Y.value()) : "";
		auto moveZText = command.m_Z ? std::format("Z{} ", command.m_Z.value()) : "";

		auto commandCode = std::format("N{} G0 {}{}{}{}\n", command.m_LineNumber, moveSpeedText, moveXText, moveYText, moveZText);

		m_FileStream << commandCode;
	}
	
	void GCodeCommandSerializerVisitor::Visit(SlowToolMoveCommand& command)
	{
		auto moveSpeedText = command.m_MoveSpeed ? std::format("F{} ", command.m_MoveSpeed.value()) : "";
		auto moveXText = command.m_X ? std::format("X{} ", command.m_X.value()) : "";
		auto moveYText = command.m_Y ? std::format("Y{} ", command.m_Y.value()) : "";
		auto moveZText = command.m_Z ? std::format("Z{} ", command.m_Z.value()) : "";

		auto commandCode = std::format("N{} G1 {}{}{}{}\n", command.m_LineNumber, moveSpeedText, moveXText, moveYText, moveZText);

		m_FileStream << commandCode;
	}
	
	void GCodeCommandSerializerVisitor::Visit(ToolSpinClockwiseEnableCommand& command)
	{
		auto rotationSpeedText = command.m_RotationSpeed ? std::format("S{} ", command.m_RotationSpeed.value()) : "";
		auto commandCode = std::format("N{} M3 {}\n", command.m_LineNumber, rotationSpeedText);

		m_FileStream << commandCode;
	}
	
	void GCodeCommandSerializerVisitor::Visit(ToolSpinCounterClockwiseEnableCommand& command)
	{
		auto rotationSpeedText = command.m_RotationSpeed ? std::format("S{} ", command.m_RotationSpeed.value()) : "";
		auto commandCode = std::format("N{} M4 {}\n", command.m_LineNumber, rotationSpeedText);

		m_FileStream << commandCode;
	}
	
	void GCodeCommandSerializerVisitor::Visit(ToolSpinDisableCommand& command)
	{
		auto commandCode = std::format("N{} M5\n", command.m_LineNumber);

		m_FileStream << commandCode;
	}
	
	void GCodeCommandSerializerVisitor::Visit(CutterCompensationDisableCommand& command)
	{
		auto commandCode = std::format("N{} G40\n", command.m_LineNumber);

		m_FileStream << commandCode;
	}
	
	void GCodeCommandSerializerVisitor::Visit(InchesUnitSystemSelectionCommand& command)
	{
		auto commandCode = std::format("N{} G20\n", command.m_LineNumber);

		m_FileStream << commandCode;
	}
	
	void GCodeCommandSerializerVisitor::Visit(MillimetersUnitSystemSelectionCommand& command)
	{
		auto commandCode = std::format("N{} G21\n", command.m_LineNumber);

		m_FileStream << commandCode;
	}
	
	void GCodeCommandSerializerVisitor::Visit(ProgramStopCommand& command)
	{
		auto commandCode = std::format("N{} M30\n", command.m_LineNumber);

		m_FileStream << commandCode;
	}
	
	void GCodeCommandSerializerVisitor::Visit(ToolPositioningAbsoluteCommand& command)
	{
		auto commandCode = std::format("N{} G90\n", command.m_LineNumber);

		m_FileStream << commandCode;
	}
	
	void GCodeCommandSerializerVisitor::Visit(ToolPositioningIncrementalCommand& command)
	{
		auto commandCode = std::format("N{} G91\n", command.m_LineNumber);

		m_FileStream << commandCode;
	}
}

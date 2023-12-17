#include "GCodeCommandSerializerVisitor.h"

#include <iomanip>
#include <sstream>
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
		auto moveSpeedText = std::string("");

		if (command.m_MoveSpeed)
		{
			auto formatter = std::stringstream();
			formatter << std::fixed << std::setprecision(3) << command.m_MoveSpeed.value();

			auto value = formatter.str();

			moveSpeedText = std::format("F{} ", value);
		}

		auto moveXText = std::string("");

		if (command.m_X)
		{
			auto formatter = std::stringstream();
			formatter << std::fixed << std::setprecision(3) << command.m_X.value();

			auto value = formatter.str();

			moveXText = std::format("X{} ", value);
		}

		auto moveYText = std::string("");

		if (command.m_Z)
		{
			auto formatter = std::stringstream();
			formatter << std::fixed << std::setprecision(3) << -command.m_Z.value();

			auto value = formatter.str();

			moveYText = std::format("Y{} ", value);
		}

		auto moveZText = std::string("");

		if (command.m_Y)
		{
			auto formatter = std::stringstream();
			formatter << std::fixed << std::setprecision(3) << command.m_Y.value();

			auto value = formatter.str();

			moveZText = std::format("Z{} ", value);
		}

		auto commandCode = std::format("N{} G0 {}{}{}{}\n", command.m_LineNumber, moveSpeedText, moveXText, moveYText, moveZText);

		m_FileStream << commandCode;
	}
	
	void GCodeCommandSerializerVisitor::Visit(SlowToolMoveCommand& command)
	{
		auto moveSpeedText = std::string("");

		if (command.m_MoveSpeed)
		{
			auto formatter = std::stringstream();
			formatter << std::fixed << std::setprecision(3) << command.m_MoveSpeed.value();

			auto value = formatter.str();

			moveSpeedText = std::format("F{} ", value);
		}

		auto moveXText = std::string("");

		if (command.m_X)
		{
			auto formatter = std::stringstream();
			formatter << std::fixed << std::setprecision(3) << command.m_X.value();

			auto value = formatter.str();

			moveXText = std::format("X{} ", value);
		}

		auto moveYText = std::string("");

		if (command.m_Z)
		{
			auto formatter = std::stringstream();
			formatter << std::fixed << std::setprecision(3) << -command.m_Z.value();

			auto value = formatter.str();

			moveYText = std::format("Y{} ", value);
		}

		auto moveZText = std::string("");

		if (command.m_Y)
		{
			auto formatter = std::stringstream();
			formatter << std::fixed << std::setprecision(3) << command.m_Y.value();

			auto value = formatter.str();

			moveZText = std::format("Z{} ", value);
		}

		auto commandCode = std::format("N{} G1 {}{}{}{}\n", command.m_LineNumber, moveSpeedText, moveXText, moveYText, moveZText);

		m_FileStream << commandCode;
	}
	
	void GCodeCommandSerializerVisitor::Visit(ToolSpinClockwiseEnableCommand& command)
	{
		auto rotationSpeedText = std::string("");

		if (command.m_RotationSpeed)
		{
			auto formatter = std::stringstream();
			formatter << std::fixed << std::setprecision(3) << command.m_RotationSpeed.value();

			auto value = formatter.str();

			rotationSpeedText = std::format("S{} ", value);
		}

		auto commandCode = std::format("N{} M3 {}\n", command.m_LineNumber, rotationSpeedText);

		m_FileStream << commandCode;
	}
	
	void GCodeCommandSerializerVisitor::Visit(ToolSpinCounterClockwiseEnableCommand& command)
	{
		auto rotationSpeedText = std::string("");

		if (command.m_RotationSpeed)
		{
			auto formatter = std::stringstream();
			formatter << std::fixed << std::setprecision(3) << command.m_RotationSpeed.value();

			auto value = formatter.str();

			rotationSpeedText = std::format("S{} ", value);
		}

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

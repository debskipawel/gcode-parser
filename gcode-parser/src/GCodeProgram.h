#pragma once

#include <memory>
#include <vector>

#include <Commands/GCodeCommand.h>

namespace GCP
{
	class GCodeProgram
	{
	public:
		GCodeProgram(std::vector<std::shared_ptr<GCodeCommand>> commands);

		virtual void Run();

	private:
		std::vector<std::shared_ptr<GCodeCommand>> m_Commands;
	};
}

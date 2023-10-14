#include "GCodeProgram.h"

namespace GCP
{
	GCodeProgram::GCodeProgram(std::vector<std::shared_ptr<GCodeCommand>> commands)
		: m_Commands(commands)
	{
	}

	void GCodeProgram::Run()
	{
	}
}

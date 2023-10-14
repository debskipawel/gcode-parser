#include "GCodeCommandVisitor.h"

namespace GCP
{
	void GCodeCommandVisitor::Visit(GCodeCommand& command)
	{
		command.Accept(*this);
	}
}

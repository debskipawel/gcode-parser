#pragma once

#include <Factories/GCodeCommandFactory.h>

namespace GCP
{
	class ProgramStopCommandFactory : public GCodeCommandFactory
	{
	public:
		explicit ProgramStopCommandFactory();

		virtual std::shared_ptr<GCodeCommand> CreateFrom(std::string codeLine) override;
	};
}

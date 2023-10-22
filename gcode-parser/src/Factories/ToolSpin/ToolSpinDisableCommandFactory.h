#pragma once

#include <Factories/GCodeCommandFactory.h>

namespace GCP
{
	class ToolSpinDisableCommandFactory : public GCodeCommandFactory
	{
	public:
		explicit ToolSpinDisableCommandFactory();

		virtual std::shared_ptr<GCodeCommand> CreateFrom(std::string codeLine) override;
	};
}

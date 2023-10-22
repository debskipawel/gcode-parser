#pragma once

#include <Factories/GCodeCommandFactory.h>

namespace GCP
{
	class ToolPositioningAbsoluteCommandFactory : public GCodeCommandFactory
	{
	public:
		explicit ToolPositioningAbsoluteCommandFactory();

		virtual std::shared_ptr<GCodeCommand> CreateFrom(std::string codeLine) override;
	};
}

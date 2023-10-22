#pragma once

#include <Factories/GCodeCommandFactory.h>

namespace GCP
{
	class ToolPositioningIncrementalCommandFactory : public GCodeCommandFactory
	{
	public:
		explicit ToolPositioningIncrementalCommandFactory();

		virtual std::shared_ptr<GCodeCommand> CreateFrom(std::string codeLine) override;
	};
}

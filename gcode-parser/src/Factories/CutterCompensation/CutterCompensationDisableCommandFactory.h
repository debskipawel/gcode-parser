#pragma once

#include <Factories/GCodeCommandFactory.h>

namespace GCP
{
	class CutterCompensationDisableCommandFactory : public GCodeCommandFactory
	{
	public:
		CutterCompensationDisableCommandFactory();

		virtual std::shared_ptr<GCodeCommand> CreateFrom(std::string codeLine) override;
	};
}

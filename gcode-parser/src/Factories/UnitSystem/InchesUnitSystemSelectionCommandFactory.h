#pragma once

#include <Factories/GCodeCommandFactory.h>

namespace GCP
{
	class InchesUnitSystemSelectionCommandFactory : public GCodeCommandFactory
	{
	public:
		InchesUnitSystemSelectionCommandFactory();

		virtual std::shared_ptr<GCodeCommand> CreateFrom(std::string codeLine) override;
	};
}
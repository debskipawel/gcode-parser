#pragma once

#include <Factories/GCodeCommandFactory.h>

namespace GCP
{
	class MillimetersUnitSystemSelectionCommandFactory : public GCodeCommandFactory
	{
	public:
		MillimetersUnitSystemSelectionCommandFactory();

		virtual std::shared_ptr<GCodeCommand> CreateFrom(std::string codeLine) override;
	};
}

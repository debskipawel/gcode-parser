#pragma once

#include <optional>

#include <Factories/GCodeCommandFactory.h>

namespace GCP
{
	class ToolSpinEnableCommandFactory : public GCodeCommandFactory
	{
	public:
		explicit ToolSpinEnableCommandFactory();

		virtual std::shared_ptr<GCodeCommand> CreateFrom(std::string codeLine) override;

	protected:
		virtual std::shared_ptr<GCodeCommand> CreateCommand(unsigned int lineNumber, std::optional<float> rotationSpeed) = 0;

		virtual std::optional<float> GetRotationSpeed(std::string codeLine);

		std::string m_RegexNumericValueRotationSpeed;
	};
}

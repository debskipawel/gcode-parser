#include "ToolSpinEnableCommandFactory.h"

#include <Factories/GCodeRegexResources.h>

namespace GCP
{
	ToolSpinEnableCommandFactory::ToolSpinEnableCommandFactory()
	{
		m_RegexNumericValueRotationSpeed = std::format("S\\s*{}", GCodeRegexResources::s_NumericValue);
	}

	std::shared_ptr<GCodeCommand> ToolSpinEnableCommandFactory::CreateFrom(std::string codeLine)
	{
		auto rotationSpeed = GetRotationSpeed(codeLine);
		auto lineNumber = LineNumber(codeLine);

		return CreateCommand(lineNumber, rotationSpeed);
	}

	std::optional<float> ToolSpinEnableCommandFactory::GetRotationSpeed(std::string codeLine)
	{
		std::smatch match;

		if (std::regex_search(codeLine, match, std::regex(m_RegexNumericValueRotationSpeed)))
		{
			auto value = match[0].str();

			std::regex_search(value, match, std::regex(GCodeRegexResources::s_NumericValue));

			return std::stof(match[0].str());
		}

		return std::nullopt;
	}
}

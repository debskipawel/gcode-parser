#include "ToolMoveCommandFactory.h"

#include <format>

#include <Commands/ToolMove/ToolMoveCommand.h>
#include <Factories/GCodeRegexResources.h>

namespace GCP
{
	ToolMoveCommandFactory::ToolMoveCommandFactory()
	{
		m_RegexNumericValueX = std::format("X\\s*{}", GCodeRegexResources::s_NumericValue);
		m_RegexNumericValueY = std::format("Y\\s*{}", GCodeRegexResources::s_NumericValue);
		m_RegexNumericValueZ = std::format("Z\\s*{}", GCodeRegexResources::s_NumericValue);

		m_RegexNumericValueF = std::format("F\\s*{}", GCodeRegexResources::s_NumericValue);
	}

	std::shared_ptr<GCodeCommand> ToolMoveCommandFactory::CreateFrom(std::string codeLine)
	{
		std::smatch match;

		auto x = GetNumericValue(m_RegexNumericValueX, codeLine);
		auto y = GetNumericValue(m_RegexNumericValueY, codeLine);
		auto z = GetNumericValue(m_RegexNumericValueZ, codeLine);

		auto speed = GetNumericValue(m_RegexNumericValueF, codeLine);

		return CreateCommand(x, y, z, speed);
	}

	std::optional<float> ToolMoveCommandFactory::GetNumericValue(const std::string& regexPattern, const std::string& codeLine)
	{
		std::smatch match;

		if (std::regex_search(codeLine, match, std::regex(regexPattern)))
		{
			auto value = match[0].str();

			std::regex_search(value, match, std::regex(GCodeRegexResources::s_NumericValue));

			return std::stof(match[0].str());
		}

		return std::nullopt;
	}
}

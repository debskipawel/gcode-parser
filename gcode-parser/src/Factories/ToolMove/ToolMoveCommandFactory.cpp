#include "ToolMoveCommandFactory.h"

#include <format>

#include <Commands/ToolMove/ToolMoveCommand.h>

namespace GCP
{
	ToolMoveCommandFactory::ToolMoveCommandFactory()
	{
		m_CommandValidationRegex = std::format("N[0-9]*[1-9]+\\s*((G0+)|(G0*1))\\s*({})?\\s*({})?\\s*({})?", s_RegexNumericValueX, s_RegexNumericValueY, s_RegexNumericValueZ);
	}

	std::shared_ptr<GCodeCommand> ToolMoveCommandFactory::CreateFrom(std::string codeLine)
	{
		std::smatch match;

		auto x = GetCoordinateValue(s_RegexNumericValueX, codeLine);
		auto y = GetCoordinateValue(s_RegexNumericValueY, codeLine);
		auto z = GetCoordinateValue(s_RegexNumericValueZ, codeLine);

		return std::make_shared<ToolMoveCommand>(x, y, z);
	}

	std::optional<float> ToolMoveCommandFactory::GetCoordinateValue(const std::string& regexPattern, const std::string& codeLine)
	{
		std::smatch match;

		if (std::regex_search(codeLine, match, std::regex(regexPattern)))
		{
			auto value = match[0].str();

			std::regex_search(value, match, std::regex(s_NumericValue));

			return std::stof(match[0].str());
		}

		return std::nullopt;
	}
}

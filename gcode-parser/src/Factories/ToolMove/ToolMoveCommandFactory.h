#pragma once

#include <format>
#include <optional>

#include <Factories/GCodeCommandFactory.h>

namespace GCP
{
	class ToolMoveCommandFactory : public GCodeCommandFactory
	{
	public:
		explicit ToolMoveCommandFactory();

		virtual std::shared_ptr<GCodeCommand> CreateFrom(std::string codeLine) override;

	protected:
		static std::optional<float> GetCoordinateValue(const std::string& regexPattern, const std::string& codeLine);

		inline static std::string s_NumericValue = "(0|(-?[1-9][0-9]*))\\.[0-9]{3}";

		inline static std::string s_RegexNumericValueX = std::format("X{}", s_NumericValue);
		inline static std::string s_RegexNumericValueY = std::format("Y{}", s_NumericValue);
		inline static std::string s_RegexNumericValueZ = std::format("Z{}", s_NumericValue);
	};
}

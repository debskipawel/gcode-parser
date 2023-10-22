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
		virtual std::shared_ptr<GCodeCommand> CreateCommand(std::optional<float> x, std::optional<float> y, std::optional<float> z, std::optional<float> speed) = 0;

		static std::optional<float> GetNumericValue(const std::string& regexPattern, const std::string& codeLine);

		std::string m_RegexNumericValueF;

		std::string m_RegexNumericValueX;
		std::string m_RegexNumericValueY;
		std::string m_RegexNumericValueZ;
	};
}

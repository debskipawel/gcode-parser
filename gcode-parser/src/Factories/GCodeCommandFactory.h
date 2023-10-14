#pragma once

#include <memory>
#include <regex>
#include <string>

#include <Commands/GCodeCommand.h>

namespace GCP
{
	class GCodeCommandFactory
	{
	public:
		virtual bool CanBeCreatedFrom(std::string codeLine);

		virtual std::shared_ptr<GCodeCommand> CreateFrom(std::string codeLine) = 0;

	protected:
		std::regex m_CommandValidationRegex;
	};
}

#pragma once

#include <format>
#include <string>

namespace GCP
{
	class GCodeRegexResources
	{
	public:
		GCodeRegexResources() = delete;

		inline static std::string s_LineNumberPrefix = "N[0-9]+";

		inline static std::string s_NumericValue = "-?(0|([1-9][0-9]*))(\\.[0-9]{3})?";
	};
}
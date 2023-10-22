#pragma once

#include <string>

#include <GCodeProgram.h>

namespace GCP
{
	enum class GCodeParserCode : unsigned int
	{
		SUCCESS = 0,
		WARNING = 1,
		PARSER_ERROR = 2,
	};

	struct GCodeParserResult
	{
	public:
		GCodeParserResult()
			: m_Result(GCodeParserCode::SUCCESS), m_Program({}), m_Message("")
		{
		}

	public:
		GCodeParserCode m_Result;
		GCodeProgram m_Program;

		std::string m_Message;
	};
}
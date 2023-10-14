#pragma once

#include <filesystem>
#include <memory>
#include <vector>

#include <Factories/GCodeCommandFactory.h>

#include <GCodeParserResult.h>

namespace GCP
{
	class GCodeParser
	{
	public:
		GCodeParser();

		GCodeParserResult LoadFromFile(std::filesystem::path filepath);

	protected:
		std::vector<std::unique_ptr<GCodeCommandFactory>> m_CommandFactories;
	};
}

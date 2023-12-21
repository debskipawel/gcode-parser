#include <iostream>
#include <format>

#include <GCodeParser.h>
#include <GCodeSerializer.h>

int main()
{
	auto parser = GCP::GCodeParser();

	auto result = parser.LoadFromFile("detail_path.k08");

	if (result.m_Result == GCP::GCodeParserCode::SUCCESS)
	{
		std::cout << "Path file parsed succesfully.\n";
	}
	else
	{
		std::cout << std::format("[PARSING ERROR]: {}\n", result.m_Message);
	}

	auto serializer = GCP::GCodeSerializer();

	serializer.Serialize(result.m_Program, "detail_path.k08");

	return 0;
}

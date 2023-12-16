#include <iostream>
#include <format>

#include <GCodeParser.h>
#include <GCodeSerializer.h>

int main()
{
	auto parser = GCP::GCodeParser();

	auto result = parser.LoadFromFile("testPathFile.f4");

	if (result.m_Result == GCP::GCodeParserCode::SUCCESS)
	{
		std::cout << "Path file parsed succesfully.\n";
	}
	else
	{
		std::cout << std::format("[PARSING ERROR]: {}\n", result.m_Message);
	}

	auto serializer = GCP::GCodeSerializer();

	serializer.Serialize(result.m_Program, "serializer_test.f04");

	return 0;
}

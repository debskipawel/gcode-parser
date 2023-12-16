#include "GCodeSerializer.h"

#include <fstream>

#include <Visitors/GCodeCommandSerializerVisitor.h>

GCP::GCodeSerializer::GCodeSerializer()
{
}

auto GCP::GCodeSerializer::Serialize(const GCodeProgram& program, const std::filesystem::path& filepath) -> void
{
	auto file = std::ofstream(filepath);

	std::unique_ptr<GCodeCommandVisitor> serializerVisitor = std::make_unique<GCodeCommandSerializerVisitor>(file);

	for (const auto& command : program.m_Commands)
	{
		serializerVisitor->Visit(*command);
	}

	file.close();
}

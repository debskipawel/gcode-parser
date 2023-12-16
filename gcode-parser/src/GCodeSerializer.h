#pragma once

#include <filesystem>

#include <GCodeProgram.h>

namespace GCP
{
	class GCodeSerializer
	{
	public:
		GCodeSerializer();

		virtual auto Serialize(const GCodeProgram& program, const std::filesystem::path& filepath) -> void;
	};
}

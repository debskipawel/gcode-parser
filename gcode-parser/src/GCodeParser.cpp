#include "GCodeParser.h"

#include <algorithm>
#include <fstream>

#include <Factories/ToolMove/ToolMoveCommandFactory.h>

namespace GCP
{
    GCodeParser::GCodeParser()
    {
        m_CommandFactories.emplace_back(std::make_unique<ToolMoveCommandFactory>());
    }

    GCodeParserResult GCP::GCodeParser::LoadFromFile(std::filesystem::path filepath)
    {
        GCodeParserResult result = {};

        const auto emptyCommands = std::vector<std::shared_ptr<GCodeCommand>>();
        auto commands = emptyCommands;
        
        if (!std::filesystem::exists(filepath) || !std::filesystem::is_regular_file(filepath))
        {
            result.m_Result = GCodeParserCode::PARSER_ERROR;
            result.m_Message = "Incorrect input file - either doesn't exist or is not a text file.";

            return result;
        }

        auto file = std::fstream(filepath.c_str(), std::ios::in);

        std::string line;
        auto lineNumber = 0;

        while (std::getline(file, line))
        {
            // TODO: skip empty lines or lines with blank characters only

            lineNumber++;

            //if (std::all_of(m_CommandFactories.begin(), m_CommandFactories.end(), [line](const auto& factory) { return !factory->CanBeCreatedFrom(line); }))
            //{
            //    result.m_Result = GCodeParserCode::PARSER_ERROR;
            //    result.m_Message = "Incorrect command detected - unhandled by the parser.";

            //    return result;
            //}

            for (auto& factory : m_CommandFactories)
            {
                if (!factory->CanBeCreatedFrom(line))
                {
                    continue;
                }

                auto command = factory->CreateFrom(line);

                commands.push_back(command);
            }
        }

        result.m_Program = GCodeProgram(commands);

        return result;
    }
}

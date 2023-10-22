#include "GCodeParser.h"

#include <algorithm>
#include <fstream>

#include <Factories/ToolMove/FastToolMoveCommandFactory.h>
#include <Factories/ToolMove/SlowToolMoveCommandFactory.h>

#include <Factories/ToolSpin/ToolSpinDisableCommandFactory.h>
#include <Factories/ToolSpin/ToolSpinClockwiseEnableCommandFactory.h>
#include <Factories/ToolSpin/ToolSpinCounterClockwiseEnableCommandFactory.h>

#include <Factories/ToolPositioning/ToolPositioningAbsoluteCommandFactory.h>
#include <Factories/ToolPositioning/ToolPositioningIncrementalCommandFactory.h>

#include <Factories/CutterCompensation/CutterCompensationDisableCommandFactory.h>

#include <Factories/UnitSystem/InchesUnitSystemSelectionCommandFactory.h>
#include <Factories/UnitSystem/MillimetersUnitSystemSelectionCommandFactory.h>

#include <Factories/ProgramStop/ProgramStopCommandFactory.h>

namespace GCP
{
    GCodeParser::GCodeParser()
    {
        m_CommandFactories.emplace_back(std::make_unique<FastToolMoveCommandFactory>());
        m_CommandFactories.emplace_back(std::make_unique<SlowToolMoveCommandFactory>());
        
        m_CommandFactories.emplace_back(std::make_unique<ToolSpinDisableCommandFactory>());
        m_CommandFactories.emplace_back(std::make_unique<ToolSpinClockwiseEnableCommandFactory>());
        m_CommandFactories.emplace_back(std::make_unique<ToolSpinCounterClockwiseEnableCommandFactory>());

        m_CommandFactories.emplace_back(std::make_unique<ToolPositioningAbsoluteCommandFactory>());
        m_CommandFactories.emplace_back(std::make_unique<ToolPositioningIncrementalCommandFactory>());

        m_CommandFactories.emplace_back(std::make_unique<CutterCompensationDisableCommandFactory>());
        
        m_CommandFactories.emplace_back(std::make_unique<InchesUnitSystemSelectionCommandFactory>());
        m_CommandFactories.emplace_back(std::make_unique<MillimetersUnitSystemSelectionCommandFactory>());

        m_CommandFactories.emplace_back(std::make_unique<ProgramStopCommandFactory>());
    }

    GCodeParserResult GCP::GCodeParser::LoadFromFile(std::filesystem::path filepath)
    {
        GCodeParserResult result = {};

        const auto emptyCommands = std::vector<std::shared_ptr<GCodeCommand>>();
        auto commands = emptyCommands;
        
        if (!std::filesystem::exists(filepath) || !std::filesystem::is_regular_file(filepath))
        {
            result.m_Result = GCodeParserCode::ERROR;
            result.m_Message = "Incorrect input file - either doesn't exist or is not a text file.";

            return result;
        }

        auto file = std::fstream(filepath.c_str(), std::ios::in);

        std::string line;
        auto lineNumber = 0, commandLineNumber = 0;

        while (std::getline(file, line))
        {
            lineNumber++;

            if (IsLineEmpty(line))
            {
                continue;
            }

            commandLineNumber++;

            if (std::all_of(m_CommandFactories.begin(), m_CommandFactories.end(), [line](const auto& factory) { return !factory->CanBeCreatedFrom(line); }))
            {
                result.m_Result = GCodeParserCode::WARNING;
                result.m_Message = std::format("Unexpected command found at line {} in the source file ({}) - skipping", lineNumber, line);
                continue;
            }

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

    bool GCodeParser::IsLineEmpty(const std::string& codeLine)
    {
        auto emptyLineRegex = std::regex("^\\s*$");

        return std::regex_match(codeLine, emptyLineRegex);
    }
}

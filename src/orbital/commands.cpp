#include "commands.h"
#include <unordered_map>

static std::unordered_map<std::string, Command> actionMap = {
    { "shutdown", Command::SHUTDOWN }
};

Command parseTerminalCommand([[maybe_unused]]const std::string& input)
{
    if (actionMap.find(input) != actionMap.end())
    {
        return actionMap[input];
    }
    return Command::UNKNOWN;
}

#ifndef COMMANDS_H
#define COMMANDS_H

#include <string>

enum class Command
{
    UNKNOWN,
    SHUTDOWN
};

Command parseTerminalCommand(const std::string& input);

#endif

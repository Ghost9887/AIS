#include "orbital_terminal.h"
#include <iostream>

class OrbitalTerminal::OrbitalTerminalImpl
{
public:
    OrbitalTerminalImpl() = default;
    ~OrbitalTerminalImpl() = default;

    Command GetCommand()
    {
        std::string userInput;
        std::cout << "> ";
        std::getline(std::cin, userInput);
        return parseTerminalCommand(userInput);
    }
public:
    bool mRunning = true;
};

OrbitalTerminal::OrbitalTerminal() :
    mImpl(std::make_unique<OrbitalTerminalImpl>()) {}

OrbitalTerminal::~OrbitalTerminal() = default;

bool OrbitalTerminal::IsRunning()
{
    return mImpl->mRunning;
}

[[nodiscard]]Command OrbitalTerminal::GetCommand()
{
    return mImpl->GetCommand();
}

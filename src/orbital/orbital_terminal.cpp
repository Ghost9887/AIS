#include "orbital_terminal.h"
#include <iostream>

class OrbitalTerminal::OrbitalTerminalImpl
{
public:
    OrbitalTerminalImpl() = default;
    ~OrbitalTerminalImpl() = default;

    std::string GetInput()
    {
        std::string userInput;
        std::cout << "> ";
        std::getline(std::cin, userInput);
        mRunning = false;
        return userInput;
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

std::string OrbitalTerminal::GetInput()
{
    return mImpl->GetInput();
}

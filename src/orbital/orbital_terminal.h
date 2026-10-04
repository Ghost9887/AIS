#ifndef ORBITAL_TERMINAL_H
#define ORBITAL_TERMINAL_H

#include <memory>
#include <string>
#include "commands.h"

class OrbitalTerminal
{
public:
    OrbitalTerminal();
    ~OrbitalTerminal();

    bool IsRunning();
    [[nodiscard]]Command GetCommand();
private:
    class OrbitalTerminalImpl;
    std::unique_ptr<OrbitalTerminalImpl> mImpl;
};

#endif

#ifndef ORBITAL_TERMINAL_H
#define ORBITAL_TERMINAL_H

#include <memory>
#include <string>

class OrbitalTerminal
{
public:
    OrbitalTerminal();
    ~OrbitalTerminal();

    bool IsRunning();
    std::string GetInput();
private:
    class OrbitalTerminalImpl;
    std::unique_ptr<OrbitalTerminalImpl> mImpl;
};

#endif

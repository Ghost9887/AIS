#include "orbital.h"
#include "orbital_terminal.h"
#include <utils.h>
#include <print>

void printPowerOn()
{
    Utils::clearScreen();
    Utils::typeln("Powering on...", Utils::Duration(0.05f));
    Utils::sleep(Utils::Duration(1.0f));
    Utils::typeln("Initializing Orbital OS...", Utils::Duration(0.05f));
    Utils::sleep(Utils::Duration(0.5f));
}

void printPowerOff()
{
    Utils::type("Shutting down...", Utils::Duration(0.07f));
    Utils::sleep(Utils::Duration(1.0f));
    Utils::clearScreen();
}

class Orbital::OrbitalImpl
{
public:
    OrbitalImpl() = default;
    ~OrbitalImpl() = default;

    void PowerOn()
    {
        printPowerOn();
    }

    void Run() 
    {
        OrbitalTerminal orbitalTerm;

        while (orbitalTerm.IsRunning())
        {
            std::println("{}", orbitalTerm.GetInput());
        }
    }

    void ShutDown()
    {
        printPowerOff();
    }
};

Orbital::Orbital() : 
    mImpl(std::make_unique<OrbitalImpl>()) {}
Orbital::~Orbital() = default;

void Orbital::PowerOn()
{
    mImpl->PowerOn();
}

void Orbital::Run()
{
    mImpl->Run();
}

void Orbital::ShutDown()
{
    mImpl->ShutDown();
}

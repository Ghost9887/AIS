#include "orbital.h"
#include "orbital_terminal.h"
#include <utils.h>
#include <print>

void printPowerOn()
{
    Utils::clearScreen();
    Utils::typeln("Powering on...", Utils::Duration(0.03f));
    Utils::sleep(Utils::Duration(1.0f));
    Utils::typeln("Starting Orbital OS...", Utils::Duration(0.03f));
    Utils::sleep(Utils::Duration(0.5f));
}

void printPowerOff()
{
    Utils::type("Shutting down...", Utils::Duration(0.03f));
    Utils::sleep(Utils::Duration(1.0f));
    Utils::clearScreen();
}

void printUnknownCommand()
{
    Utils::typeln(
        "Uknown terminal command type 'help' for a list of available commands", 
        Utils::Duration(0.013f)
    );
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

        while (mRunning)
        {
            Command cmd = orbitalTerm.GetCommand();
            if (cmd == Command::SHUTDOWN) 
                mRunning = false;
            else if (cmd == Command::UNKNOWN)
                printUnknownCommand();
        }
    }

    void ShutDown()
    {
        printPowerOff();
    }
public:
    bool mRunning = true;
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

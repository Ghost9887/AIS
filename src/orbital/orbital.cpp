#include "orbital.h"
#include <utils.h>
#include <print>

class Orbital::OrbitalImpl
{
public:
    OrbitalImpl() = default;
    ~OrbitalImpl() = default;

    void PowerOn()
    {
        Utils::clearScreen();
        Utils::typeln("Powering on...", Utils::Duration(0.07f));
        Utils::sleep(Utils::Duration(1.0f));
    }

    void ShutDown()
    {
        Utils::type("Shutting down...", Utils::Duration(0.07f));
        Utils::sleep(Utils::Duration(1.0f));
        Utils::clearScreen();
    }
};

Orbital::Orbital() : 
    mImpl(std::make_unique<OrbitalImpl>()) {}
Orbital::~Orbital() = default;

void Orbital::PowerOn()
{
    mImpl->PowerOn();
}

void Orbital::ShutDown()
{
    mImpl->ShutDown();
}

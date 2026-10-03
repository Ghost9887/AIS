#ifndef ORBITAL_H
#define ORBITAL_H

#include <memory>

class Orbital
{
public:
    Orbital();
    ~Orbital();

    void PowerOn();
    void ShutDown();
private:
    class OrbitalImpl;
    std::unique_ptr<OrbitalImpl> mImpl;
};

#endif

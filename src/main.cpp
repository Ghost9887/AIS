#include "orbital/orbital.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] const char** argv)
{
    Orbital orbital;

    orbital.PowerOn();

    orbital.Run();

    orbital.ShutDown();

    return 0;
}

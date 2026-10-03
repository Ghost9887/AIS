#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>
#include <thread>
#include <chrono>

namespace Utils
{
    
    struct Duration { float value; };

    void clearScreen()
    {
        std::cout << "\033[H\033[2J";
    }
    
    void sleep(const Duration duration)
    {
        std::this_thread::sleep_for(std::chrono::duration<float>(duration.value));
    }

    void type(const std::string& text, const Duration duration)
    {
        for (char c : text)
        {
            std::cout << c << std::flush;
            sleep(duration);
        }
    }

    void typeln(const std::string& text, const Duration duration)
    {
        for (char c : text)
        {
            std::cout << c << std::flush;
            sleep(duration);
        }
        std::cout << std::endl;
    }
}

#endif

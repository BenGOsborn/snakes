#include <iostream>
#include "Engine.hpp"
#include "IEngine.hpp"
#include <chrono>
#include <memory>
#include <thread>
#include <termios.h>

void startLoop(const IEngine *engine)
{
    int x = 10;
    int y = 10;
    bool running = true;

    while (running)
    {
        engine->clearScreen();

        // draw player
        for (int i = 0; i < y; i++)
            std::cout << "\n";
        for (int i = 0; i < x; i++)
            std::cout << " ";
        std::cout << "@\n";

        // handle input
        std::unique_ptr<int> keyPtr = engine->pollKey();
        if (keyPtr != nullptr)
        {
            int key = *keyPtr;
            if (key == 'a')
                x--; // move left
            if (key == 'd')
                x++; // move right
            if (key == 'w')
                y--; // move left
            if (key == 's')
                y++; // move right
            if (key == 'q')
                running = false;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(50)); // ~20 FPS
    }
}

int main()
{
    termios terminal{};
    std::unique_ptr<IEngine> engine = std::make_unique<Engine>(terminal);

    startLoop(engine.get());

    return 0;
}
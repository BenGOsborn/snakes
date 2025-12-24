#include <iostream>
#include "Engine.hpp"
#include "IEngine.hpp"
#include "State.hpp"
#include "IState.hpp"
#include <chrono>
#include <memory>
#include <vector>
#include <thread>
#include <termios.h>
#include <iomanip>

// Need to limit to the size of your terminal (including the additional characters used in the printer)
const int GRID_SIZE = 25;

void printScreen(IState *state)
{
    std::vector<std::vector<Tile>> grid = state->getTiles();
    for (const std::vector<Tile> &row : grid)
    {
        for (const Tile &elem : row)
        {
            std::cout << std::setw(1) << static_cast<char>(elem);
        }
        std::cout << '\n';
    }
    std::cout << std::flush;
}

void startLoop(const IEngine *engine, IState *state)
{
    while (state->isRunning())
    {
        engine->clearScreen();

        std::unique_ptr<int> keyPtr = engine->pollKey();
        if (keyPtr != nullptr)
        {
            int key = *keyPtr;
            if (key == 'a')
                state->updateDirection(Direction::Left);
            if (key == 'd')
                state->updateDirection(Direction::Right);
            if (key == 'w')
                state->updateDirection(Direction::Up);
            if (key == 's')
                state->updateDirection(Direction::Down);
        }

        state->run();

        printScreen(state);

        std::this_thread::sleep_for(std::chrono::milliseconds(200)); // ~20 FPS
    }
}

int main()
{
    termios terminal{};
    std::unique_ptr<IEngine> engine = std::make_unique<Engine>(terminal);
    std::unique_ptr<IState> state = std::make_unique<State>(GRID_SIZE, GRID_SIZE);

    startLoop(engine.get(), state.get());

    return 0;
}
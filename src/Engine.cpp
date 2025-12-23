#include "Engine.hpp"
#include <memory>
#include <string>
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

static const std::string CLEAR_SCREEN = "\033[2J\033[H";

Engine::Engine(termios &terminal) : base(terminal)
{
    termios newt;
    tcgetattr(STDIN_FILENO, &terminal);
    newt = terminal;
    newt.c_lflag &= ~(ICANON | ECHO); // no buffering, no echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK); // non-blocking
}

Engine::~Engine()
{
    tcsetattr(STDIN_FILENO, TCSANOW, &base);
}

void Engine::clearScreen()
{
    std::cout << CLEAR_SCREEN;
}

std::unique_ptr<int> Engine::pollKey()
{
    int ch = getchar();
    if (ch == EOF)
    {
        return nullptr;
    }
    return std::make_unique<int>(ch);
}
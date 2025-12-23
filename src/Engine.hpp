#pragma once
#include "IEngine.hpp"
#include <termios.h>
#include <memory>

class Engine : public IEngine
{
    termios &base;

public:
    Engine(termios &terminal);
    ~Engine();
    void clearScreen() override;
    std::unique_ptr<int> pollKey() override;
};
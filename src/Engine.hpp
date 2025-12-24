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
    void clearScreen() const override;
    std::unique_ptr<int> pollKey() const override;
};
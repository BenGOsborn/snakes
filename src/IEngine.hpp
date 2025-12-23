#pragma once
#include <memory>

class IEngine
{
public:
    virtual ~IEngine() = default;
    virtual void clearScreen() = 0;
    virtual std::unique_ptr<int> pollKey() = 0;
};
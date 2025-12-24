#pragma once
#include <memory>

class IEngine
{
public:
    virtual ~IEngine() = default;
    virtual void clearScreen() const = 0;
    virtual std::unique_ptr<int> pollKey() const = 0;
};
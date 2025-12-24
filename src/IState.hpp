#pragma once
#include <vector>

enum class Direction : int
{
    Up = 'w',
    Down = 's',
    Left = 'a',
    Right = 'd'
};

class IState
{
public:
    virtual ~IState() = default;
    virtual void updateDirection(Direction direction) noexcept = 0;
    virtual void run() = 0;
    virtual std::vector<std::vector<int>> getOutput() const noexcept = 0;
    virtual bool isRunning() const noexcept = 0;
};
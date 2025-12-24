#pragma once
#include <vector>

enum class Direction : int
{
    Up = 'w',
    Down = 's',
    Left = 'a',
    Right = 'd'
};

enum class Tile : char
{
    Empty = ' ',
    Snake = '*',
    SnakeHead = '@',
    Fruit = '#',
};

class IState
{
public:
    virtual ~IState() = default;
    virtual void updateDirection(Direction direction) noexcept = 0;
    virtual void run() noexcept = 0;
    virtual std::vector<std::vector<Tile>> getTiles() const noexcept = 0;
    virtual bool isRunning() const noexcept = 0;
};
#pragma once
#include "IState.hpp"
#include <vector>
#include <set>

struct Position
{
    int x;
    int y;

    bool operator<(const Position &other) const
    {
        return std::tie(x, y) < std::tie(other.x, other.y);
    }

    bool operator==(const Position &other) const
    {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Position &other) const
    {
        return x != other.x || y != other.y;
    }

    Position operator+(const Position &other) const
    {
        return Position{x + other.x, y + other.y};
    }
};

struct Snake
{
    Direction direction;
    std::vector<Position> position;
    std::set<Position> index;
};

class State : public IState
{
    int width;
    int height;
    bool running;
    Snake snake;
    Position fruit;

    Snake buildSnake() const noexcept;
    Position buildFruit() const noexcept;
    Position buildPosition(Position other, Direction direction) const;

public:
    State(int width, int height);
    ~State() override = default;
    void updateDirection(Direction direction) noexcept override;
    void run() noexcept override;
    std::vector<std::vector<Tile>> getTiles() const noexcept override;
    bool isRunning() const noexcept override;
};
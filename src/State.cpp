#include "State.hpp"
#include <vector>
#include <ranges>
#include <random>

State::State(int width, int height) : width(width), height(height), running(true), snake(buildSnake()), fruit(buildFruit())
{
    if (width < 1 || height < 1)
    {
        throw std::runtime_error("grid must be at least 1x1");
    }
}

Position State::buildFruit() const noexcept
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distWidth(0, width - 1);
    std::uniform_int_distribution<int> distHeight(0, height - 1);
    int fruitX = distWidth(gen);
    int fruitY = distHeight(gen);
    return Position{fruitX, fruitY};
}

Snake State::buildSnake() const
{
    Position position{};
    Snake snake{
        Direction::Right,
        {{0, 0}},
        {{0, true}},
    };
    return snake;
}

void State::updateDirection(Direction direction) noexcept
{
    snake.direction = direction;
}

void State::run() noexcept {}

std::vector<std::vector<Tile>> State::getTiles() const noexcept
{
    std::vector<std::vector<Tile>> grid(height);
    for (int i = 0; i < height; i++)
    {
        std::vector<Tile> row(width);
    }
    std::vector<Tile> row = grid.at(fruit.y);
    row[fruit.x] = Tile::Fruit;
    for (size_t i = 0; i < snake.position.size(); ++i)
    {
        Tile body = Tile::Snake;
        if (i == 0)
        {
            body = Tile::SnakeHead;
        }
        Position position = snake.position.at(i);
        std::vector<Tile> row = grid.at(position.y);
        row[position.x] = body;
    }
    return grid;
}

bool State::isRunning() const noexcept
{
    return running;
}
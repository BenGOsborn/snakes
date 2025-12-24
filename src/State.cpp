#include "State.hpp"
#include <vector>

State::State(int maxFruit, int width, int height) : maxFruit(maxFruit), width(width), height(height)
{
    if (width <= 0 || height <= 0)
    {
        throw std::runtime_error("width and height must be at least 1");
    }
    Position position = {0, 0};
    snake = std::vector<Position>{position};
}
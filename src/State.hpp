#pragma once
#include "IState.hpp"
#include <vector>

struct Position
{
    int x;
    int y;
};

class State : public IState
{
    std::vector<Position> snake;
    int maxFruit;
    int width;
    int height;

public:
    State(int maxFruit, int width, int height);
    ~State();
    void updateDirection(Direction direction) noexcept override;
    void run() override;
    std::vector<std::vector<int>> getOutput() const noexcept override;
    bool isRunning() const noexcept override;
};
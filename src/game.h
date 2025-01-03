#ifndef GAME_H
#define GAME_H

#include "food.h"
#include "snake.h"
#include <raylib.h>

class Game {
public:
    Game();
    void Run();
private:
    int cellSize;
    int cellCount;
    double lastUpdateTime;
    Color backgroundColor;
    Food food;
    Snake snake;
    void GameOver();
    void Initialize();
    void Update();
    void Draw();
    void CheckCollisionWithTail();
    void CheckCollisionWithEdges();
    void CheckCollisionWithFood();
    bool eventTriggered(double interval);
};

#endif // GAME_H
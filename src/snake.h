#ifndef SNAKE_H
#define SNAKE_H

#include <raylib.h>
#include <deque>

class Snake
{   
public:
    Vector2 direction;
    Snake();
    ~Snake();
    std::deque<Vector2> body;
    bool grow;
    void addSegment();
    void Draw();
    void Update();
};

#endif // SNAKE_H
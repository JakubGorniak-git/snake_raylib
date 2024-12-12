#ifndef FOOD_H
#define FOOD_H

#include <raylib.h>

class Food
{   
public:
    Vector2 position;
    Food();
    ~Food();
    void Draw();
    Vector2 GenerateRandomPos();
};

#endif // FOOD_H
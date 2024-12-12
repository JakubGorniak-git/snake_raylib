#include "food.h"
#include <iostream>

Food::Food() {
    position = GenerateRandomPos();
}

Food::~Food() {
    std::cout << "food end" << std::endl;
}

void Food::Draw() {
    Color darkGreen = {100, 12, 24, 255};
    DrawRectangle(position.x * 30, position.y * 30, 30, 30, darkGreen);
}

Vector2 Food::GenerateRandomPos() {
    float x = GetRandomValue(0, 39);
    float y = GetRandomValue(0, 39);
    return Vector2{x, y};
}
#include "snake.h"
#include <iostream>
#include <raymath.h>

Snake::Snake() {
     body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
     grow = false;
     direction = {1,0};
}

Snake::~Snake() {
    std::cout << "snake end" << std::endl;
}

void Snake::addSegment(){
    body.push_front(Vector2Add(body[0], direction));
}

void Snake::Reset(){
    body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    direction = {1,0};
}
void Snake::Draw() {
    Color darkGreen = {43, 51, 24, 255};
    for (unsigned int i = 0; i < body.size(); i++) {
        int x = static_cast<int>(body[i].x);
        int y = static_cast<int>(body[i].y);
        DrawRectangle(x * 30, y * 30, 30, 30, darkGreen);
    }
}


void Snake::Update(){
    // If not growing, remove the last segment
    if (!grow) {
        body.pop_back();
    }
    // Always add a new segment at the head
    body.push_front(Vector2Add(body[0], direction));
    
    // Reset grow flag
    grow = false;
}
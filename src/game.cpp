#include "game.h"
#include <iostream>
#include <raymath.h>
#include <deque>

Game::Game() : cellSize(30), cellCount(40), lastUpdateTime(0),
               backgroundColor{173, 204, 96, 255}, 
               food(),
               snake() {
    std::cout << "Game starting" << std::endl;
}

void Game::Initialize() {
    SetTargetFPS(60);
    InitWindow(cellSize * cellCount, cellSize * cellCount, "Retro Snake");
}

void Game::Update() {
    if (eventTriggered(0.2)) {
        snake.Update();
    }

    if (IsKeyPressed(KEY_UP) && snake.direction.y != 1){
        snake.direction = {0,-1};
    }
    if (IsKeyPressed(KEY_DOWN) && snake.direction.y != -1){
        snake.direction = {0,1};
    }
    if (IsKeyPressed(KEY_RIGHT) && snake.direction.x != -1){
        snake.direction = {1,0};
    }
    if (IsKeyPressed(KEY_LEFT) && snake.direction.x != 1){
        snake.direction = {-1,0};
    }
    CheckCollisionWithFood();
    CheckCollisionWithEdges();
    CheckCollisionWithTail();
}

void Game::GameOver(){
    snake.Reset();
    food.position = food.GenerateRandomPos();
    std::cout << "Game Over" << std::endl;
}

bool ElementInDeque(const Vector2& element, const std::deque<Vector2>& deq) {
    for (const auto& item : deq) {
        if (item == element) {
            return true;
        }
    }
    return false;
}
void Game::CheckCollisionWithTail(){
    std::deque<Vector2> headlessBody = snake.body;
    headlessBody.pop_front();
    if(ElementInDeque(snake.body[0], headlessBody)){
        GameOver();
    }
}

void Game::CheckCollisionWithEdges(){
    if (snake.body[0].x == cellCount || snake.body[0].x == -1){
        GameOver();
    }
    if (snake.body[0].y == cellCount || snake.body[0].y == -1){
        GameOver();
    }
}
void Game::CheckCollisionWithFood(){
    // Check if snake's head is on the food position
    if (Vector2Equals(snake.body[0], food.position)){
        // Generate new food position
        food.position = food.GenerateRandomPos();
        
        // Mark snake to grow
        snake.grow = true;
        
        // Add a new segment to the snake
        snake.addSegment();
    }
}

bool Game::eventTriggered(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

void Game::Draw() {
    BeginDrawing();
    ClearBackground(backgroundColor);
    food.Draw();
    snake.Draw();
    EndDrawing();
}

void Game::Run() {
    Initialize();
    while (!WindowShouldClose()) {
        Update();
        Draw();
    }
    CloseWindow();
}
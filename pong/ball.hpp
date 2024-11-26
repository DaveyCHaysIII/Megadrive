#include "raylib.h"
#include <cstdlib>

class Ball {
public:
    Vector2 position;
    Vector2 speed;
    float radius;

    Ball(float screenWidth, float screenHeight, float ballRadius)
        : position{screenWidth / 2, screenHeight / 2},
          speed{200.0f, 200.0f},
          radius{ballRadius} {}

    void Move(float deltaTime) {
        position.x += speed.x * deltaTime;
        position.y += speed.y * deltaTime;
    }

    void CheckCollisionWithWalls(float screenHeight) {
        if (position.y - radius <= 0 || position.y + radius >= screenHeight) {
            speed.y *= -1; // Reverse vertical direction
        }
    }

    bool CheckCollisionWithPaddle(Rectangle paddle) {
        if (CheckCollisionCircleRec(position, radius, paddle)) {
            speed.x *= -1; // Reverse horizontal direction
            return true;
        }
        return false;
    }

    void Reset(float screenWidth, float screenHeight) {
        position = {screenWidth / 2, screenHeight / 2};
        speed = {300.0f, (rand() % 2 == 0 ? -300.0f : 300.0f)};
    }

    void Draw() const {
        DrawCircleV(position, radius, BLACK);
    }
};



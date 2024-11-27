#include "raylib.h"
#include <cstdlib>
#include <random>

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
        // Initialize random engine and distribution
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<int> dist(0, 1);

        // Generate a random value (0 or 1)
        int randint = dist(gen);

        position = {screenWidth / 2, screenHeight / 2};
        speed = {300.0f, randint == 0 ? -300.0f : 300.0f};
    }


    void Draw() const {
        DrawCircleV(position, radius, BLACK);
    }
};



#include "raylib.h"
#include <cstdlib>
#include <random>
#include <chrono>

class Ball {
public:
    Vector2 position;
    Vector2 speed;
    float radius;

    Ball(float screenWidth, float screenHeight, float ballRadius)
        : position{screenWidth / 2, screenHeight / 2},
          speed{200.0f, 200.0f},
          radius{ballRadius} {}

    void Update(float deltaTime) {
        position.x += speed.x * deltaTime;
        position.y += speed.y * deltaTime;
    }

    void incrSpeed() {
        if (speed.x < 0)
            speed.x -= 10.0f;
        else
            speed.x += 10.0f;
        if (speed.y < 0)
            speed.y -= 10.0f;
        else
            speed.y += 10.0f;
    }

    void CheckCollisionWithWalls() {
        if (position.y - radius <= 100 || position.y + radius >= (GetScreenHeight() - 100)) {
            speed.y *= -1; // Reverse vertical direction
        }
    }

    bool CheckCollisionWithPaddle(Vector2 paddleV, float width, float height) {
        if (CheckCollisionCircleRec(position, radius, Rectangle{paddleV.x, paddleV.y, width, height})) {
            speed.x *= -1; // Reverse horizontal direction
            return true;
        }
        return false;
    }


    void Reset(float screenWidth, float screenHeight) {
        position.x = screenWidth / 2;
        position.y = screenHeight / 2;

        auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        std::mt19937 rng(static_cast<unsigned int>(seed));
        std::uniform_int_distribution<int> dist(1,100);
        auto rand_int = dist(rng);

        if (rand_int >= 1 && rand_int <= 25) {
            speed.x = 200.0f;
            speed.y = 200.0f;
        }
        else if (rand_int >= 26 && rand_int <= 50) {
            speed.x = -200.0f;
            speed.y = 200.0f;
        }
        else if (rand_int >= 51 && rand_int <= 75) {
            speed.x = -200.0f;
            speed.y = -200.0f;
        }
        else {
            speed.x = 200.0f;
            speed.y = -200.0f;
        }
    }

    void Draw() const {
        DrawCircleV(position, radius, BLACK);
    }
};



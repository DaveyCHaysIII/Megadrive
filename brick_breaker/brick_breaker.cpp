#include "bbheader.hpp"
#include <raylib.h>

using namespace brickbreaker;

int main (int argc, char **argv) {
    brickbreaker::Screen_Draw brickBreakerGame("Brick Breaker", 1280, 800, 800, 600);
    brickBreakerGame.Init();

    while (!WindowShouldClose()) {
        // updates

        // Drawing

    }
    CloseWindow();
    return (0);
}

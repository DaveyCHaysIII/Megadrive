#ifndef SCREEN_HPP_
#define SCREEN_HPP_

#include <raylib.h>
#include "paddle.hpp"
#include "ball.hpp"

class Screen {
public:
    const char *title;
    Vector2 viewportCoord;

    Screen(const char *title, float viewport_x_pos, float viewport_y_pos) :
    title(title),
    viewportCoord{viewport_x_pos, viewport_y_pos} {}
};

class Title : public Screen {
public:
    using Screen::Screen; // use Screen constructor

    void Draw() {
        ClearBackground(WHITE);
	DrawText("PONG", viewportCoord.x + 340, viewportCoord.y + 100, 60, DARKGREEN);
	DrawText("Made by: Logan Wyatt", viewportCoord.x + 245, viewportCoord.y + 200, 30, DARKGREEN);
    }
};

class Gameplay : public Screen {
public:
    using Screen::Screen; // use Screen constructor

    void Draw(Ball ball, Paddle left, Paddle right) {
        ClearBackground(RAYWHITE);
	ball.Draw();
	left.Draw();
	right.Draw();
	DrawText("Press ESC to exit", viewportCoord.x + 600, viewportCoord.y + 580, 20, LIGHTGRAY);
    }
};

class Ending : public Screen {
public:
    using Screen::Screen; // use Screen constructor

    void Draw() {
        ClearBackground(BLUE);
	DrawText("Ending Screen", viewportCoord.x + 20, viewportCoord.y + 20, 40, DARKGREEN);
	DrawText("Tap ESC to EXIT", viewportCoord.x + 50, viewportCoord.y + 100, 20, DARKGREEN);

    }
};

#endif // SCREEN_HPP_

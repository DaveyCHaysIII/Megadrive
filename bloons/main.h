#ifndef BLOONS_H
#define BLOONS_H

#include <raylib.h>
#include <iostream>
#include <vector>

#define DEFAULT_POSITION ((Vector2){ 1200.0f, 740.0f })
#define COORDS_COLOR BLACK
#define WIN_WIDTH 1280
#define WIN_HEIGHT 800
#define WINDOW_COLOR GOLD
#define GAME_X 240
#define GAME_Y 100
#define GAME_WIDTH 800
#define GAME_HEIGHT 600
#define GAME_COLOR RAYWHITE
#define TARGET_FPS 60
#define LOGO_POSX 10
#define LOGO_POSY 10
#define LOGO_SIZE 30
#define LOGO_COLOR BLACK

/**
 * useful numbers to know:
 *
 * Center: X = 640, Y= 400;
 * available pixels X = 240 - 640, then 640 - 1040 (400 per half)
 * available pixels Y = 100 - 400, then 400 - 700  (300 per half)
 */

void display_mouse_coords(Vector2 text_position, int text_size, Color text_color);
#endif

#ifndef MY_GAME_H
#define MY_GAME_H

//------includes
#include <raylib.h>
#include <stddef.h>

//------defines
#define DEFAULT_POSITION ((Vector2){ 1200.0f, 740.0f })
#define PALETTE_COUNT 3
#define MAX_SOUNDS 5
#define MAX_TEXTURES 10

//------structs

typedef struct
{
	Color window;
	Color game;
	Color window_txt_fore;
	Color window_txt_back;
	Color game_txt_fore;
	Color game_txt_back;
} Palette;

typedef struct
{
	Palette colors;
	Music music;

	Sound *soundEffects;
	int soundCount;

	Texture2D *textures;
	int textureCount;
} Gamestate;

static const Palette palettes[PALETTE_COUNT] =
{
	{ DARKGRAY, GRAY, WHITE, LIGHTGRAY, RAYWHITE, BLACK },
	{ DARKBLUE, GRAY, WHITE, LIGHTGRAY, RAYWHITE, BLACK },
	{ PINK, PURPLE, WHITE, LIGHTGRAY, RAYWHITE, BLACK }
};

//------funcs

void display_mouse_coords(Vector2, int, Color);
void init_game(int argc, char **argv, Gamestate *state);
#endif

#ifndef MY_GAME_H
#define MY_GAME_H

//------includes
#include <raylib.h>
#include <stddef.h>
#include <cstdio>
#include <iostream>
//------defines
#define DEFAULT_POSITION ((Vector2){ 1200.0f, 740.0f })
#define MAX_SOUNDS 5
#define MAX_TEXTURES 10
#define TARGET_FPS 60
#define LOGO_POSX 10
#define LOGO_POSY 10
#define LOGO_SIZE 30
#define GAME_X 240
#define GAME_Y 100
#define GAME_HEIGHT 600
#define GAME_WIDTH 800
#define SET_FLAG(flags, flag) ((flags).all_flags |= (flag))
#define CLEAR_FLAG(flags, flag) ((flags).all_flags &= ~(flag))
#define CHECK_FLAG(flags, flag) ((flags).all_flags & (flag))
#define TOGGLE_FLAG(flags, flag) ((flags) ^= (flag))
//------structs


enum Gamestate
{
	SPLASH,
	GAME_PLAYING,
	GAME_OVER,
	SCORE_BOARD
};

enum Directions
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

typedef struct Flags
{
	unsigned int all_flags;

	enum
	{
		FLAG_ONE   = 1 << 0,
		FLAG_TWO   = 1 << 1,
		FLAG_THREE = 1 << 2,
		FLAG_FOUR  = 1 << 3
	}
}

enum color_list
{
	BACKGROUND,
	FOREGROUND,
	BACKGROUND_TEXT,
	FOREGROUND_TEXT,
	WINDOW_BACKGROUND,
	WINDOW_TEXT
}



//------funcs

void init(int, char**, int *, Color *, Texture2d *)
void display_mouse_coords(Vector2, int, Color);
double getFrames(void);
int timer(int, double, int);
int countDownTimer(int, double, int);
int formatTimer(int, char *);
int drawCurtains(int, int, int, int, Color, int);
int fadeToBlack(int, int, int, int, int);
int fadeFromBlack(int, int, int, int, int);
#endif

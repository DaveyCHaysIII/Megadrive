#ifndef MY_GAME_H
#define MY_GAME_H

//------includes
#include <raylib.h>
#include <stddef.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstring>
#include <stdio.h>

//------defines
#define DEFAULT_POSITION ((Vector2){ 1200.0f, 740.0f })
#define MAX_SOUNDS 5
#define MAX_TEXTURES 10
#define MAX_TIMERS 10
#define MAX_CHAR 500
#define MAX_COLORS 7
#define MAX_RECTANGLES 10
#define TARGET_FPS 60
#define LOGO_POSX 10
#define LOGO_POSY 10
#define LOGO_SIZE 30
#define BOARD_POSX 420
#define BOARD_POSY 180
#define BOARD_HEIGHT 440
#define BOARD_WIDTH 440
#define BLOCK_HEIGHT 140
#define BLOCK_WIDTH 140
#define GAME_X 240
#define GAME_Y 100
#define GAME_HEIGHT 600
#define GAME_WIDTH 800
#define SET_FLAG(flags, flag) ((flags).all_flags |= (flag))
#define CLEAR_FLAG(flags, flag) ((flags).all_flags &= ~(flag))
#define CHECK_FLAG(flags, flag) ((flags).all_flags & (flag))
#define TOGGLE_FLAG(flags, flag) ((flags) ^= (flag))
//------structs


enum State
{
	SPLASH,
	GAME_PLAYING,
	GAME_OVER,
	SCORE_BOARD,
	END
};

enum Turn
{
	TURN_X,
	TURN_O
};

enum color_list
{
	BACKGROUND,
	FOREGROUND,
	BACKGROUND_TEXT,
	FOREGROUND_TEXT,
	WINDOW_BACKGROUND,
	WINDOW_TEXT,
	ACCENT
};

enum textures
{
	MARQUIS, 
	SPRITES
};

enum Rects
{
	MARQUIS_SOURCE,
	PLAYER_X,
	PLAYER_O
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
	};
} Flags;

typedef struct Timer
{

	int frames;
	int is_complete;
} Timer;


typedef struct Gamestate
{
	int gameState;

	Color colors[MAX_COLORS];
	Texture2D textures[MAX_TEXTURES];
	Timer timers[MAX_TIMERS];
	Rectangle rectangles[MAX_RECTANGLES];
	double frameCount;


} Gamestate;



//------funcs

void init_game(int, char**, Gamestate *);
void init_timers(Timer *, int);
void splash(Gamestate *);
void game_playing(Gamestate *);
void game_over(Gamestate *);
void scoreBoard(Gamestate *);

int checkWinner(int, const int *);
double getFrames(void);
void display_mouse_coords(Vector2, int, Color);
int startTimer(Timer *, int, double, int);
void resetTimer(Timer *);
int formatTimer(int, char *);
int drawCurtains(int, int, int, int, Color, int);
int fadeToBlack(int);
int fadeFromBlack(int);

//------util funcs

Texture2D LoadTextureFromPath(const std::string& filename, const std::string& basePath);
Sound LoadSoundFromPath(const std::string& filename, const std::string& basePath);
#endif

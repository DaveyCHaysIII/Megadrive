#ifndef PONG_H_
#define PONG_H_

// LIBRARIES

#include <raylib.h>
#include <stdio.h>

// MACROS

#define PLAYER_WIDTH 20
#define PLAYER_HEIGHT 100

// STRUCTS

typedef struct window_fmt_s
{
	const int WindowWidth = 1280;
	const int WindowHeight = 800;
	const int ViewportWidth = 800;
	const int ViewportHeight = 600;
	const int ViewportX = (WindowWidth - ViewportWidth) / 2;
	const int ViewportY = (WindowHeight - ViewportHeight) / 2;
} window_fmt_t;

typedef struct player_objs
{
	Rectangle player1 = { 270, 400, PLAYER_WIDTH, PLAYER_HEIGHT };
	Rectangle player2 = { 990, 400, PLAYER_WIDTH, PLAYER_HEIGHT };
} player_objs_t;

// PROTOTYPES

// INIT.CPP

int func(void);

#endif // PONG_H_

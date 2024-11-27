#ifndef PONG_H_
#define PONG_H_

// LIBRARIES

#include "raylib.h"

// MACROS

#define PLAYER_WIDTH 20
#define PLAYER_HEIGHT 100

// STRUCTS

typedef struct window_fmt_s
{
	float WindowWidth = 1280;
	float WindowHeight = 800;
	float ViewportWidth = 800;
	float ViewportHeight = 600;
	float ViewportX = (WindowWidth - ViewportWidth) / 2;
	float ViewportY = (WindowHeight - ViewportHeight) / 2;
} window_fmt_t;

typedef struct player_objs
{
	Rectangle player1 = { 270, 400, PLAYER_WIDTH, PLAYER_HEIGHT };
	Rectangle player2 = { 990, 400, PLAYER_WIDTH, PLAYER_HEIGHT };
} player_objs_t;

typedef struct Ball_s
{
	Vector2 position;
	Vector2 speed;
	float radius;
} Ball_t;

// PROTOTYPES

int InitBall(Ball_s *ball, float screenwidth, float screenheight);
void DrawBall(Ball_s ball);

// INIT.CPP

int func(void);

#endif

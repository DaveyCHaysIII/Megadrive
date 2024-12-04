#ifndef PONG_H_
#define PONG_H_

// LIBRARIES

// MACROS

#define PLAYER_WIDTH 10
#define PLAYER_HEIGHT 100

// STRUCTS

typedef enum GameScreen { TITLE, GAMEPLAY, ENDING } GameScreen_t;

typedef struct window_fmt_s
{
	float WindowWidth = 1280;
	float WindowHeight = 800;
	float ViewportWidth = 800;
	float ViewportHeight = 600;
	float ViewportX = (WindowWidth - ViewportWidth) / 2;
	float ViewportY = (WindowHeight - ViewportHeight) / 2;
	GameScreen_t currentScreen = TITLE;
} window_fmt_t;

// PROTOTYPES

#endif

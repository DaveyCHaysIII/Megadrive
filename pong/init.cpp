#include "raylib.h"

#define PLAYER_WIDTH 50
#define PLAYER_HEIGHT 100

int func()
{
	// Set Window Size
	const int WindowWidth = 1280;
	const int WindowHeight = 800;

	// Set PlayArea / viewport
	const int PlayAreaWidth = 800;
	const int PlayAreaHeight = 600;
	const int PlayAreaX = (WindowWidth - PlayAreaWidth) / 2;
	const int PlayAreaY = (WindowHeight - PlayAreaHeight) / 2;

	InitWindow(WindowWidth, WindowHeight, "pong window");

	SetTargetFPS(60); // Set target frame rate for game
	
	return (0);
}

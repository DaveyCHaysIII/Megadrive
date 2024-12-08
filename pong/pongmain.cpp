#include "ball.hpp"
#include "paddle.hpp"
#include "screen.hpp"
#include <cstdio>
#include <cstring>
#include <raylib.h>

#define PADDLE_WIDTH 10
#define PADDLE_HEIGHT 100
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 800
#define VIEWPORT_WIDTH 800
#define VIEWPORT_HEIGHT 600
#define VIEWPORT_X ((WINDOW_WIDTH - VIEWPORT_WIDTH) / 2)
#define VIEWPORT_Y ((WINDOW_HEIGHT - VIEWPORT_HEIGHT) / 2)

#define COMPUTER 1
#define PLAYER 0

static int initializePaddlesByPlayerType(char *, Paddle *, Paddle *);

typedef enum GameScreen { TITLE, GAMEPLAY } GameScreen_t; // TODO: Add scoring and gameover screen

/**
 * main - Entry point for pong game
 * @argc: Number of arguments passed into game
 * @argc: Matrix of passed arguments
 *
 * Return: 0 on success, otherwise 1
 */

int main(int argc, char **argv)
{
	// Check if Game is executed properly
	if (argc == 1 || argc > 2)
	{
		std::printf("USAGE: ./pong <#player>\n");
		std::printf("Where # is number of players, 0 - 2\n");
		return (1);
	}

	// Declare and/or init variables
	Paddle leftpaddle, rightpaddle;
	GameScreen_t currentScreen = TITLE;
	Title controlsScreen("Pong Title", VIEWPORT_X, VIEWPORT_Y);
	Gameplay gameplayScreen("Pong Gameplay", VIEWPORT_X, VIEWPORT_Y);
	Ending ScoreScreen("Scores", VIEWPORT_X, VIEWPORT_Y);
	Ball ball(WINDOW_WIDTH, WINDOW_HEIGHT, 10.0f);
	int frm_cnt = 0;

	initializePaddlesByPlayerType(argv[1], &leftpaddle, &rightpaddle);

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Pong Game");
	SetTargetFPS(60);
	InitAudioDevice();

	Music music = LoadMusicStream("assets/Funtime_Frolick.mp3");
	Sound collisionSound = LoadSound("assets/boop.wav");

	SetMusicVolume(music, .5);
	PlayMusicStream(music);

	while (!WindowShouldClose())
	{
		UpdateMusicStream(music);
		// updates for specific screens
		switch (currentScreen) {
			case TITLE:
			{
				if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
					currentScreen = GAMEPLAY;
			} break;
			case GAMEPLAY:
			{
				float deltatime = GetFrameTime();

				//update ball
				ball.Update(deltatime);
				ball.CheckCollisionWithWalls(collisionSound);
				ball.CheckCollisionWithPaddle(leftpaddle.position, leftpaddle.p_width, leftpaddle.p_height, collisionSound);
				ball.CheckCollisionWithPaddle(rightpaddle.position, rightpaddle.p_width, rightpaddle.p_height, collisionSound);
				if (ball.position.x < VIEWPORT_X || ball.position.x > (VIEWPORT_X + VIEWPORT_WIDTH))
				ball.Reset(WINDOW_WIDTH, WINDOW_HEIGHT);

				// Update paddles
				leftpaddle.Update(ball.position);
				rightpaddle.Update(ball.position);
				// if (IsKeyPressed(KEY_ENTER))
				//	currentScreen = ENDING;
			} break;
			// case ENDING:
			// {
			//	if (IsKeyPressed(KEY_ESCAPE))
			//		WindowShouldClose();
			// } break;
		}

		// Begin Drawing
		BeginDrawing();
		ClearBackground(BLACK);

		BeginScissorMode(VIEWPORT_X, VIEWPORT_Y, VIEWPORT_WIDTH, VIEWPORT_HEIGHT);
	
		// Drawing switch
		switch (currentScreen) {
			case TITLE: {
				controlsScreen.Draw();
			} break;
			case GAMEPLAY: {
				gameplayScreen.Draw(ball, leftpaddle, rightpaddle);
				frm_cnt++;
				if (frm_cnt % 120 == 0)
					ball.incrSpeed();
			} break;
			// case ENDING: {
			//	ScoreScreen.Draw();
			// } break;
		}
        	EndScissorMode();

		EndDrawing();
	}
	// Unloading Audio
	UnloadMusicStream(music);
	UnloadSound(collisionSound);

	CloseAudioDevice();

	CloseWindow();

	return (0);
}

/**
 * initializePaddleByPlayerType - initializes left and right paddles based on number of players
 * @player: char * - Number of players
 * @left: Paddle * - Pointer to left paddle
 * @right: Paddle * - Pointer to right paddle
 *
 * Return: 0 on success, otherwise 1
 */

static int initializePaddlesByPlayerType(char *player, Paddle *left, Paddle *right) {
	if (std::strcmp(player, "0player") == 0)
	{
		left->init(250, (WINDOW_HEIGHT / 2) - (PADDLE_HEIGHT / 2), PADDLE_WIDTH, PADDLE_HEIGHT, 3.0f, KEY_W, KEY_S, BLUE, COMPUTER);
		right->init(1030 - PADDLE_WIDTH, (WINDOW_HEIGHT / 2) - (PADDLE_HEIGHT / 2), PADDLE_WIDTH, PADDLE_HEIGHT, 3.0f, KEY_UP, KEY_DOWN, RED, COMPUTER);
		return (0);
	}
	else if (std::strcmp(player, "1player") == 0)
	{
		left->init(250, (WINDOW_HEIGHT / 2) - (PADDLE_HEIGHT / 2), PADDLE_WIDTH, PADDLE_HEIGHT, 3.0f, KEY_W, KEY_S, BLUE, COMPUTER);
		right->init(1030 - PADDLE_WIDTH, (WINDOW_HEIGHT / 2) - (PADDLE_HEIGHT / 2), PADDLE_WIDTH, PADDLE_HEIGHT, 3.0f, KEY_UP, KEY_DOWN, RED, PLAYER);
		return (0);
	}
	else if (std::strcmp(player, "2player") == 0)
	{
		left->init(250, (WINDOW_HEIGHT / 2) - (PADDLE_HEIGHT / 2), PADDLE_WIDTH, PADDLE_HEIGHT,
		3.0f, KEY_W, KEY_S, BLUE, PLAYER);
		right->init(1030 - PADDLE_WIDTH, (WINDOW_HEIGHT / 2) - (PADDLE_HEIGHT / 2), PADDLE_WIDTH, PADDLE_HEIGHT, 3.0f, KEY_UP, KEY_DOWN, RED, PLAYER);
		return(0);
	}
	else
	{
		std::printf("USAGE: ./pong <#player>\n");
		std::printf("Where # is number of players, 0 - 2\n");
		return (1);
	}

}

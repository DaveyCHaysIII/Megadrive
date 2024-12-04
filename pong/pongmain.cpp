#include "pheader.hpp"
#include "ball.hpp"
#include "paddle.hpp"
#include "screen.hpp"
#include <raylib.h>

#define PADDLE_WIDTH 10
#define PADDLE_HEIGHT 100
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 800


int main()
{
	window_fmt_t Window;
	Paddle player1 (250, Window.WindowHeight / 2, PADDLE_WIDTH, PADDLE_HEIGHT, 3.0f, KEY_W, KEY_S, BLUE);
	Paddle player2 (1030 - PADDLE_WIDTH, Window.WindowHeight / 2, PADDLE_WIDTH, PADDLE_HEIGHT, 3.0f, KEY_UP, KEY_DOWN, RED);
	Ball ball(Window.WindowWidth, Window.WindowHeight, 10.0f);
	int frm_cnt = 0;

	InitWindow(Window.WindowWidth, Window.WindowHeight, "Pong Game");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		// updates for specific screens
		switch (Window.currentScreen) {
			case TITLE:
			{
				if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
					Window.currentScreen = GAMEPLAY;
			} break;
			case GAMEPLAY:
			{
				float deltatime = GetFrameTime();

				//update ball
				ball.Move(deltatime);
				ball.CheckCollisionWithWalls();
				ball.CheckCollisionWithPaddle(player1.position, player1.p_width, player1.p_height);
				ball.CheckCollisionWithPaddle(player2.position, player2.p_width, player2.p_height);
				if (ball.position.x < Window.ViewportX || ball.position.x > (Window.ViewportX + Window.ViewportWidth))
				ball.Reset(Window.WindowWidth, Window.WindowHeight);

				// Update paddles
				player1.Move();
				player2.Move();
				if (IsKeyPressed(KEY_ENTER))
					Window.currentScreen = ENDING;
			} break;
			case ENDING:
			{
				if (IsKeyPressed(KEY_ESCAPE))
					WindowShouldClose();
			} break;
		}

		// Begin Drawing
		BeginDrawing();
		ClearBackground(BLACK);

		BeginScissorMode(Window.ViewportX, Window.ViewportY, Window.ViewportWidth, Window.ViewportHeight);
	
		// Drawing switch
		switch (Window.currentScreen) {
			case TITLE: {
				ClearBackground(BLUE);
				DrawText("Title Screen: put options here", Window.ViewportX + 20, Window.ViewportY + 20, 40, DARKGREEN);
				DrawText("Tap ENTER or TAP to go to GAMEPLAY", Window.ViewportX + 50, Window.ViewportHeight / 2, 20, DARKGREEN);
			} break;
			case GAMEPLAY: {
				ClearBackground(RAYWHITE);
				ball.Draw();
				player1.Draw();
				player2.Draw();
				frm_cnt++;
				if (frm_cnt % 120 == 0)
					ball.incrSpeed();
			} break;
			case ENDING: {
				ClearBackground(BLUE);
				DrawText("Ending Screen", Window.ViewportX + 20, Window.ViewportY + 20, 40, DARKGREEN);
				DrawText("Tap ESC to EXIT", Window.ViewportX + 50, Window.ViewportHeight / 2, 20, DARKGREEN);

			} break;
		}
        	EndScissorMode();

		EndDrawing();
	}
	CloseWindow();

	return (0);
}

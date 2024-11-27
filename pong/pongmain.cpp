#include "pongmain.hpp"
#include "ball.hpp"
#include <raylib.h>

int main()
{
	window_fmt_t Window;
	player_objs_t players;
	Ball ball(Window.WindowWidth, Window.WindowHeight, 10.0f);

	InitWindow(Window.WindowWidth, Window.WindowHeight, "Pong Game");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		float deltatime = GetFrameTime();
		//update ball
		ball.Move(deltatime);
		ball.CheckCollisionWithWalls(Window.ViewportHeight);
		ball.CheckCollisionWithPaddle(players.player1);
		ball.CheckCollisionWithPaddle(players.player2);
		if (ball.position.x < Window.ViewportX || ball.position.x > (Window.ViewportX + Window.ViewportWidth))
			ball.Reset(Window.WindowWidth, Window.WindowWidth);
		// Update paddles
		if (IsKeyDown(KEY_W) && players.player1.y >= Window.ViewportY)
			players.player1.y -= 3.0f;
		else if (IsKeyDown(KEY_S) && players.player1.y <= (Window.ViewportY + 500))
			players.player1.y += 3.0f;

		if (IsKeyDown(KEY_UP) && players.player2.y >= Window.ViewportY)
			players.player2.y -= 3.0f;
		else if (IsKeyDown(KEY_DOWN) && players.player2.y <= (Window.ViewportY + 500))
			players.player2.y += 3.0f;

		BeginDrawing();
		ClearBackground(BLACK);

		BeginScissorMode(Window.ViewportX, Window.ViewportY, Window.ViewportWidth, Window.ViewportHeight);
		ClearBackground(RAYWHITE);
		ball.Draw();
		DrawRectangleRec(players.player1, RED);
		DrawRectangleRec(players.player2, BLUE);
        	EndScissorMode();

		EndDrawing();
	}
	CloseWindow();

	return (0);
}

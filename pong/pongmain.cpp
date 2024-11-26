#include "raylib.h"
#include "pongmain.hpp"

int main()
{
	window_fmt_t Window;
	player_objs_t players;

	InitWindow(Window.WindowWidth, Window.WindowHeight, "Pong");

	while (!WindowShouldClose())
	{
		// Update if needed
		if (IsKeyDown(KEY_W)) players.player1.y -= 3.0f;
		else if (IsKeyDown(KEY_S)) players.player1.y += 3.0f;

		if (IsKeyDown(KEY_UP)) players.player2.y -= 3.0f;
		else if (IsKeyDown(KEY_DOWN)) players.player2.y += 3.0f;

		BeginDrawing();
		ClearBackground(BLACK);

		BeginScissorMode(Window.ViewportX, Window.ViewportY, Window.ViewportWidth, Window.ViewportHeight);
		ClearBackground(RAYWHITE);
		DrawRectangleRec(players.player1, RED);
		DrawRectangleRec(players.player2, BLUE); 
        	EndScissorMode();

		EndDrawing();
	}
	CloseWindow();
	printf("Done\n");

	return (0);
}

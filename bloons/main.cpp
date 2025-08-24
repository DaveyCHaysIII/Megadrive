#include "main.h"

//
// yeah if this style of comments is good enough for John Carmack
// its good enough for me
//
// This is bloons, a balloon popping game
// Its mascot is Happy Howie, the silly clown
// I want to make this game the example game to show other devs
// so I want it running right and looking clean
//

int main() {

	SetTargetFPS(TARGET_FPS);
	InitWindow(WIN_WIDTH, WIN_HEIGHT, "Raylib Game");

	Bloon::LoadBloonTexture("./assets/bloon-texture-atlas.png");

	Game game;

	while(!WindowShouldClose())
	{
		//suggestion for timer:
		//float dt = GetFrameTime(); - gets time since last frame
		//use:
		//update(dt); class will be responsible for using dt
		BeginDrawing();
		//can we encapsulate some of these into like an init_window() function?
		ClearBackground(WINDOW_COLOR);
		DrawText("MEGADrive!", LOGO_POSX, LOGO_POSY, LOGO_SIZE, LOGO_COLOR);
		DrawRectangle(GAME_X, GAME_Y, GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);
		BeginScissorMode(GAME_X, GAME_Y, GAME_WIDTH, GAME_HEIGHT);

		//main update/draw
		game.Update();
		game.Draw();

		EndScissorMode();
		display_mouse_coords(DEFAULT_POSITION, 20, COORDS_COLOR);
		EndDrawing();
		if (IsKeyPressed(KEY_ESCAPE))
			break;
	}
	Bloon::UnloadBloonTexture();
	CloseWindow();
}


void display_mouse_coords(Vector2 text_position, int text_size, Color text_color)
{
	Vector2 mousePosition = GetMousePosition();

	DrawText(TextFormat("X: %i",
			(int)mousePosition.x),
			text_position.x,
			text_position.y,
			text_size,
			text_color);

        DrawText(TextFormat("Y: %i",
			(int)mousePosition.y),
			text_position.x,
			text_position.y + (float)text_size,
			text_size,
			text_color);
};

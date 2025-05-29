#include "main.h"

int main(int argc, char **argv, char **env) {

	SetTargetFPS(TARGET_FPS);
	InitWindow(WIN_WIDTH, WIN_HEIGHT, "Raylib Game");

	Bloon::LoadBloonTexture("./assets/bloon-texture-atlas.png");
	std::vector<Bloon> bloons(10);
	float spawntimer = 0.0f;
	const float spawnInterval = 1.0f;


	while(!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WINDOW_COLOR);
		DrawText("MEGADrive!", LOGO_POSX, LOGO_POSY, LOGO_SIZE, LOGO_COLOR);
		DrawRectangle(GAME_X, GAME_Y, GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);
		BeginScissorMode(GAME_X, GAME_Y, GAME_WIDTH, GAME_HEIGHT);

		spawntimer += GetFrameTime();
		if (spawntimer >= spawnInterval)
		{
			spawntimer = 0.0f;

			for (Bloon& b : bloons)
			{
				if (!b.active)
				{
					b.active = true;
					break;
				}
			}
		}
		for (Bloon& b : bloons)
		{
			b.Update();
			b.Draw();
		}

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

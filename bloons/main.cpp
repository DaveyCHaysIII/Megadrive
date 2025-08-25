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
	Shader addShader = LoadShader(0, "additive.fs");

	int addTintLoc = GetShaderLocation(addShader, "tintColor");
	int addStrengthLoc = GetShaderLocation(addShader, "strength");
	float addTint[3] = {1.0f, 0.8f, 0.8f};
	float addStrength = 0.0f;
	int loops = 0;

	Game game;
	Timer timer;

	while(!WindowShouldClose())
	{
		float dt = GetFrameTime();
		if (game.GetGameTime() > 0)
			game.Update(dt);
		else
		{
			if (timer.Expired())
				timer.StartLoop(1.0f);
			else if (timer.GetNumLoops() > loops && addStrength < 1)
			{
				loops++;
				addStrength += 0.4f;
				if (addStrength > 1.0)
					addStrength = 1.0;
			}
			timer.Update(dt);
		}

		BeginDrawing();
		ClearBackground(WINDOW_COLOR);
		DrawText("MEGADrive!", LOGO_POSX, LOGO_POSY, LOGO_SIZE, LOGO_COLOR);

		BeginShaderMode(addShader);
		SetShaderValue(addShader, addTintLoc, addTint, SHADER_UNIFORM_VEC3);
		SetShaderValue(addShader, addStrengthLoc, &addStrength, SHADER_UNIFORM_FLOAT);
		DrawRectangle(GAME_X, GAME_Y, GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);
		BeginScissorMode(GAME_X, GAME_Y, GAME_WIDTH, GAME_HEIGHT);

		game.Draw();

		EndScissorMode();
                EndShaderMode();

		if (addStrength >= 1)
		{
			DrawText("THE END", WIN_MID_X - 80, WIN_MID_Y, 35, WHITE);
		}
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

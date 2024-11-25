#include "main.h"

int main(int argc, char **argv, char **env) {
	// Initialize the window
	InitWindow(1280, 800, "Raylib Game");
	Gamestate state;
	init_game(argc, argv, &state);
	Vector2 mouse_coords_txt = DEFAULT_POSITION;

	// Main game loop
	while (!WindowShouldClose())
	{
	//-------------- Draw space
	BeginDrawing();
	ClearBackground(state.colors.window);
	DrawText("MEGADrive!", 10, 10, 30, state.colors.window_txt_fore);

	//game area
	DrawRectangle(240, 100, 800, 600, state.colors.game);

	display_mouse_coords(mouse_coords_txt, 20, state.colors.window_txt_back);
	EndDrawing();
	//--------------

	if (IsKeyPressed(KEY_ESCAPE))
		break;
	}

	// Close the window
	CloseWindow();
	return 0;
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
}

void init_game(int argc, char **argv, Gamestate *state)
{

	if (argc < 2)
	{
		state->colors = palettes[0];
		state->music = (Music){ 0 };
		state->soundEffects = NULL;
		state->textures = NULL;
		state->soundCount = 0;
		state->textureCount = 0;
	}
	/*else
	{
		//argv[0] - game state 0
		//argv[1] - game state 1
		//argv[2] - game state 2
	}*/
}

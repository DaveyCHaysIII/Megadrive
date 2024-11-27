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
	SetTargetFPS(TARGET_FPS);
	DrawText("MEGADrive!", 10, 10, 30, state.colors.window_txt_fore);

	//game area
	DrawRectangle(240, 100, 800, 600, state.colors.game);
	DrawRectangle(240, 100, 800, 600,

	display_mouse_coords(mouse_coords_txt, 20, state.colors.window_txt_back);
	EndDrawing();
	//--------------

	if (IsKeyPressed(KEY_ESCAPE))
		break;
	state->frameCount++;
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
		state->frameCount = 0; //ALWAYS init to 0
	}
	/*else
	{
		//argv[0] - game state 0
		//argv[1] - game state 1
		//argv[2] - game state 2
	}*/
}

int timer(double seconds)
{
	double time = (seconds * TARGET_FPS)
	if (time < (seconds * TARGET_FPS) + 1)
		time += state->frameCount;
	if (time <= state->frameCount)
		return (1);
	return (0);
}

int countDownTimer(int seconds)
{
	static int countDownSecs = 0;
	static double targetFrames = 0;

	if (targetFrames = 0)
	{
		countDownSecs = seconds;
		targetFrames = state->framecount + (seconds * TARGET_FPS);
	}
	if (state->frameCount >= targetFrames - (countDownSecs * TARGET_FPS)
	{
		countDownSecs--;
	}
	return countDownSecs;
}

int formatTimer(int timeInSeconds, char *buffer)
{
	if (timeInSeconds > 5999) || (sizeof(buffer) < 6) //"99:60"
		return (-1);
	int minutes = timeInSeconds / 60;
	int seconds = timeInSeconds % 60;

	std::sprintf(buffer, "%02d:%02d", minutes, seconds);
	return 0;
}

void drawCurtains(posX, posY, height, width, color, speed)
{
	static int curtain_height = 0;
	int curtain_width = width;
	color.a = 128;
	DrawRectangle(posX, posY, curtain_width, curtain_height, color)

	if (curtain_height < height)
	{
		curtain_height += 1 + speed;
	}
}

void fadeToBlack(posX, posY, height, width, speed)
{
	static int fade = 0;

	Color color = { 0, 0, 0, fade };
	DrawRectangle(posX, posY, curtain_width, curtain_height, color)

	if (curtain_height < height)
	{
		curtain_height += 1 + speed;
	}
}

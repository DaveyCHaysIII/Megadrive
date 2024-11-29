#include "main.h"

//---------------------------------------Main function

int main(int argc, char **argv, char **env) {
	SetTraceLogLevel(LOG_ERROR);
	// Initialize the window
	InitWindow(1280, 800, "Raylib Game");

	//--------------------------Init
	int *current_game_state;
	Color *colors;
	Texture2d *textures;
	double framecount;
	//look into how audio works?

	init(argc, argv, current_game_state, colors, textures);

	while (!WindowShouldClose())
	{
		framecount = getFrames();
		//-------------------------Draw space
		BeginDrawing();
		ClearBackground(colors[WINDOW_BACKGROUND]);
		DrawText("MEGADrive!", LOGO_POSX, LOGO_POSY, LOGO_SIZE, colors[WINDOW_TEXT]);
		DrawRectangle(GAME_X, GAME_Y, GAME_WIDTH, GAME_HEIGHT, colors[BACKGROUND]);
		//-------------------------Game Area
		if (current_game_state = SPLASH)
			splash();
		else if (current_game_state = GAME_PLAYING)
			game_playing();
		else if (current_game_state = GAME_OVER)
			game_over();
		else if (current_game_state = SCORE_BOARD)
			scoreBoard();

		//-------------------------Close

		display_mouse_coords(DEFAULT_POSITION, 20, colors[WINDOW_TEXT]);
		EndDrawing();
		//-------------------------End

		if (IsKeyPressed(KEY_ESCAPE))
			break;
	}

	// Close the window
	CloseWindow();
	return 0;
}


//----------------------------------------- Game Specific Functions

void init_game(int argc, char **argv, int *state, Color *gameColors, Texture2d *textures)
{

	if (argc < 2)
	{
		const char *asset_fp = ""; //filepath to assets directory
		state = SPLASH;
		gameColors =
		[
			GRAY,
			LIGHTGRAY,
			DARKGRAY,
			GRAY,
			BLACK,
			GREEN
		];
		textures =
		[
			LoadTexture(),
			LoadTexture(),
			//etc
		];



	}
	/*else
	{
		//argv[0] - game state 0
		//argv[1] - game state 1
		//argv[2] - game state 2
	}*/
}

void splash(int *state)
{
	//insert splash logic here

	state = GAME_PLAYING;
};
void game_playing(int *state)
{
	//insert game_playing logic here
};

void game_over()
{
	//instert game_over logic here
};

void scoreBoard()
{
	//insert scoreboard logic here
};

//-----------------------------------Begin library candidate Functions

double getFrames()
{
	static double frames = 0;
	frames++;
	return frames;
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

int timer(int seconds, double framecount, int target_fps)
{
	double time = (seconds * target_fps);
	if (time < (seconds * target_fps) + 1)
		time += frameCount;
	if (time <= frameCount)
		return (1);
	return (0);
}

int countDownTimer(int seconds, double frameCount, int target_fps)
{
	static int countDownSecs = 0;
	static double targetFrames = 0;

	if (targetFrames == 0)
	{
		countDownSecs = seconds;
		targetFrames = frameCount + (seconds * target_fps);
	}
	if (frameCount >= targetFrames - (countDownSecs * target_fps))
	{
		countDownSecs--;
	}
	return countDownSecs;
}

int formatTimer(int timeInSeconds, char *buffer)
{
	if ((timeInSeconds > 5999) || (sizeof(buffer) < 6)) //"99:60"
		return (-1);
	int minutes = timeInSeconds / 60;
	int seconds = timeInSeconds % 60;

	std::sprintf(buffer, "%02d:%02d", minutes, seconds);
	return 0;
}

int drawCurtains(int posX, int posY, int height, int width, Color color, int speed, int direction)
{
	//todo: implement directionality
	(void)direction;
	static int curtain_height = 0;
	int curtain_width = width;
	color.a = 128;
	DrawRectangle(posX, posY, curtain_width, curtain_height, color);

	if (curtain_height < height)
	{
		curtain_height += 1 + speed;
		return (0);
	}
	return (1);
}

int fadeToBlack(int posX, int posY, int height, int width, int speed)
{
	static unsigned char fade = 0;

	Color color = { 0, 0, 0, fade };
	DrawRectangle(posX, posY, width, height, color);
	if (fade == 255)
		return 1

	if ((fade + (1 + speed)) <= 255)
		fade += (1 + speed);
	else
		fade = 255;
	return (0);
}

int fadeFromBlack(int posX, int posY, int height, int width, int speed)
{
	static unsigned char fade = 255;

	Color color = { 0, 0, 0, fade };
	DrawRectangle(posX, posY, width, height, color);
	if (fade == 0)
		return 1

	if ((fade - (1 + speed)) >= 0)
		fade -= (1 + speed);
	else
		fade = 0;
	return (0);
}

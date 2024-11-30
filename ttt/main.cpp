#include "main.h"

//---------------------------------------Main function

int main(int argc, char **argv, char **env) {
	SetTraceLogLevel(LOG_ERROR);
	// Initialize the window
	InitWindow(1280, 800, "Raylib Game");

	//--------------------------Init
	Gamestate current_game_state;
	Color colors[MAX_COLORS];
	double frameCount;

	init_game(argc, argv, &current_game_state, colors);

	while (!WindowShouldClose())
	{
		frameCount = getFrames();
		//-------------------------Draw space
		BeginDrawing();
		ClearBackground(colors[WINDOW_BACKGROUND]);
		DrawText("MEGADrive!", LOGO_POSX, LOGO_POSY, LOGO_SIZE, colors[WINDOW_TEXT]);
		DrawRectangle(GAME_X, GAME_Y, GAME_WIDTH, GAME_HEIGHT, colors[BACKGROUND]);
		//-------------------------Game Area
		if (current_game_state == SPLASH)
			splash(&current_game_state, colors);
		else if (current_game_state == GAME_PLAYING)
			game_playing(&current_game_state, colors);
		else if (current_game_state == GAME_OVER)
			game_over(&current_game_state, colors);
		else if (current_game_state == SCORE_BOARD)
			scoreBoard(&current_game_state, colors);
		else if (current_game_state == END)
			break;

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

void init_game(int argc, char **argv, Gamestate *state, Color *gameColors)
{
	//static std::string BASE_PATH = "./assets/";

	if (argc < 2)
	{
		//BASE_PATH = "./assets/"; //filepath to assets directory
		*state = SPLASH;

		/*
		std::string texturePath = "ttt_spritesheet.png";
    		std::string sound1Path = "Placeholder_ducktales.ogg";
    		std::string sound2Path = "MEGAdrive.wav";
		*/
		gameColors[BACKGROUND] = GRAY;
		gameColors[FOREGROUND] = LIGHTGRAY;
		gameColors[BACKGROUND_TEXT] = DARKGRAY;
		gameColors[FOREGROUND_TEXT] = GRAY;
		gameColors[WINDOW_BACKGROUND] = BLACK;
		gameColors[WINDOW_TEXT] = GREEN;

		/*
		textures[0] = LoadTextureFromPath(texturePath, BASE_PATH);

		sounds[0] = LoadSoundFromPath(sound1Path, BASE_PATH);
		sounds[1] = LoadSoundFromPath(sound2Path, BASE_PATH);
		*/
	}
	/*else
	{
		//argv[0] - game state 0
		//argv[1] - game state 1
		//argv[2] - game state 2
	}*/
	else
	{
		return;
	}
}

void splash(Gamestate *state, Color *colors)
{
	//insert splash logic here
	DrawText("SPLASH!", 620, 400, 20, colors[BACKGROUND_TEXT]);
	if (IsKeyPressed(KEY_SPACE))
		*state = GAME_PLAYING;
};
void game_playing(Gamestate *state, Color *colors)
{
	//insert game_playing logic here
	DrawText("GAME PLAYING!", 620, 400, 20, colors[BACKGROUND_TEXT]);

	if (IsKeyPressed(KEY_SPACE))
		*state = GAME_OVER;
};

void game_over(Gamestate *state, Color *colors)
{
	//insert game_over logic here
	DrawText("GAME OVER!", 620, 400, 20, colors[BACKGROUND_TEXT]);
	if (IsKeyPressed(KEY_SPACE))
		*state = SCORE_BOARD;
	if (IsKeyPressed(KEY_G))
		*state = GAME_PLAYING;
};

void scoreBoard(Gamestate *state, Color *colors)
{
	//insert scoreboard logic here
	DrawText("SCORE BOARD!", 620, 400, 20, colors[BACKGROUND_TEXT]);
	if (IsKeyPressed(KEY_SPACE))
		*state = END;
};

//-----------------------------------Begin library candidate Functions

double getFrames()
{
	static double frames = 0;
	frames++;
	return frames;
};

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

int timer(int seconds, double frameCount, int target_fps)
{
	double time = (seconds * target_fps);
	if (time < (seconds * target_fps) + 1)
		time += frameCount;
	if (time <= frameCount)
		return (1);
	return (0);
};

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
};

int formatTimer(int timeInSeconds, char *buffer)
{
	if ((timeInSeconds > 5999) || (sizeof(buffer) < 6)) //"99:60"
		return (-1);
	int minutes = timeInSeconds / 60;
	int seconds = timeInSeconds % 60;

	std::sprintf(buffer, "%02d:%02d", minutes, seconds);
	return 0;
};

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
};

int fadeToBlack(int posX, int posY, int height, int width, int speed)
{
	static unsigned char fade = 0;

	Color color = { 0, 0, 0, fade };
	DrawRectangle(posX, posY, width, height, color);
	if (fade == 255)
		return (1);

	if ((fade + (1 + speed)) <= 255)
		fade += (1 + speed);
	else
		fade = 255;
	return (0);
};

int fadeFromBlack(int posX, int posY, int height, int width, int speed)
{
	static unsigned char fade = 255;

	Color color = { 0, 0, 0, fade };
	DrawRectangle(posX, posY, width, height, color);
	if (fade == 0)
		return (1);

	if ((fade - (1 + speed)) >= 0)
		fade -= (1 + speed);
	else
		fade = 0;
	return (0);
};

std::string GetFullPath(const std::string& filename, const std::string& basePath)
{
	return basePath + filename;
};

Texture2D LoadTextureFromPath(const std::string& filename, const std::string& basePath)
{
	std::string fullPath = GetFullPath(filename, basePath);
	return LoadTexture(fullPath.c_str());
};

Sound LoadSoundFromPath(const std::string& filename, const std::string& basePath)
{
	std::string fullPath = GetFullPath(filename, basePath);
	return LoadSound(fullPath.c_str());
}



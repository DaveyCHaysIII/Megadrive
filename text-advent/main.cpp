#include "main.h"

//---------------------------------------Main function

int main(int argc, char **argv, char **env) {
	SetTraceLogLevel(LOG_ERROR);
	// Initialize the window
	InitWindow(1280, 800, "Raylib Game");
	InitAudioDevice();
	//--------------------------Init
	Gamestate state;
	SetTargetFPS(TARGET_FPS);

	init_game(argc, argv, &state);

	while (!WindowShouldClose())
	{
		state.frameCount = getFrames();
		//-------------------------Draw space
		BeginDrawing();
		ClearBackground(state.colors[WINDOW_BACKGROUND]);
		DrawText("MEGADrive!", LOGO_POSX, LOGO_POSY, LOGO_SIZE, state.colors[WINDOW_TEXT]);
		DrawRectangle(GAME_X, GAME_Y, GAME_WIDTH, GAME_HEIGHT, state.colors[BACKGROUND]);
		//-------------------------Game Area
		if (state.gameState == SPLASH)
			splash(&state);
		else if (state.gameState == GAME_PLAYING)
			game_playing(&state);
		else if (state.gameState == GAME_OVER)
			game_over(&state);
		else if (state.gameState == SCORE_BOARD)
			scoreBoard(&state);
		else if (state.gameState == END)
			break;

		//-------------------------Close

		display_mouse_coords(DEFAULT_POSITION, 20, state.colors[WINDOW_TEXT]);
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

void init_game(int argc, char **argv, Gamestate *state)
{
	if (argc < 2)
	{
		state->gameState   = SPLASH;
		state->m_off       = 0;
		state->s_off       = 0;
		state->d_off       = 0;
		state->disposition = 0;
		state->expression  = 0;

		state->colors[BACKGROUND]        = BLACK;
		state->colors[DIALOGUE]          = BLACK;
		state->colors[LILGREEN_TEXT]     = GREEN;
		state->colors[NARRATOR_TEXT]     = RED;
		state->colors[WINDOW_BACKGROUND] = BLACK;
		state->colors[WINDOW_TEXT]       = RED;
		state->colors[ACCENT]            = YELLOW;
		

		state->textures[MARQUIS]     = LoadTexture("./assets/marquis.png");
		state->textures[SPRITES]     = LoadTexture("./assets/sprites.png");
		state->textures[DIRECTIONAL] = LoadTexture("./assets/sprites.png");
		state->textures[SCORE]       = LoadTexture("./assets/score.png");

		state->rectangles[MARQUIS]       = { 0.0f + (32 * offset), 0.0f, 64.0f, 16.0f };
		state->rectangles[BACKDROP_1]    = {};
		state->rectangles[BACKDROP_2]    = {};
		state->rectangles[BACKDROP_3]    = {};
		state->rectangles[BACKDROP_4]    = {};
		state->rectangles[DIRECTIONAL]   = {};
		state->rectangles[LILGREEN_BASE] =

		init_timers(state->timers, MAX_TIMERS);
		state->frameCount = 0;
	}
	/*
	else
	{
		if (std::strcmp(argv[1], "1") == 0)
		{
			//PRARIE

		}
		else if (std::strcmp(argv[1], "2") == 0)
		{
			//SEAS
		}
		else if (std::strcmp(argv[1], "3") == 0)
		{
			//SKIES
		}
		else if (std::strcmp(argv[1], "4") == 0)
		{
			//OCEAN
		}
		else if (std::strcmp(argv[1], "5" == 0)
		{
			//EXPANSE
		}
		else 
		{
			//FOREST


		}

	}
	*/
}

void init_timers (Timer *timers, int num_timers)
{
	for (int i = 0; i < num_timers; i++)
	{
		timers[i].frames = 0;
		timers[i].is_complete = 0;
	}

}

void splash(Gamestate *state)
{
	//-----------------------------------SPLASH
	Rectangle marquis_dest = { 340.0f, 200.0f, 600.0f, 150.0f };
	Rectangle marquis_source = state->rectangles[MARQUIS_SOURCE];
	Texture2D texture = state->textures[MARQUIS];

	DrawText("Press [SPACE] to play!", 465, 550, 30, state->colors[BACKGROUND_TEXT]);
	DrawTexturePro(texture, marquis_source, marquis_dest, (Vector2){ 0, 0}, 0, WHITE);
	if (IsKeyPressed(KEY_SPACE))
		state->gameState = GAME_PLAYING;
};


void game_playing(Gamestate *state)
{

	//---------------------------------MAIN GAME
	
	if (IsKeyPressed(KEY_SPACE))
		state->gameState = GAME_OVER;
};


void game_over(Gamestate *state)
{
	//---------------------------------GAME OVER
	DrawText("GAME OVER!", 620, 400, 20, state->colors[BACKGROUND_TEXT]);
	fadeFromBlack(1);
	if (IsKeyPressed(KEY_SPACE))
		state->gameState = SCORE_BOARD;
	if (IsKeyPressed(KEY_G))
		state->gameState = GAME_PLAYING;
};

void scoreBoard(Gamestate *state)
{
	//---------------------------------SCORE BOARD
	DrawText("SCORE BOARD!", 620, 400, 20, state->colors[BACKGROUND_TEXT]);
	fadeFromBlack(1);
	if (IsKeyPressed(KEY_SPACE))
		state->gameState = END;
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

int startTimer(Timer *timer, int seconds, double frameCount, int fps)
{
	if (timer->is_complete == 1)
		return (0);
	if (timer->frames == 0)
		timer->frames = frameCount + (seconds * fps);
	if (timer->frames <= frameCount)
	{
		timer->is_complete = 1;
		return (0);
	}
	return (1);
}

void resetTimer(Timer *timer)
{
	timer->frames = 0;
	timer->is_complete = 0;
}


int formatTimer(int timeInSeconds, char *buffer)
{
	if ((timeInSeconds > 5999) || (sizeof(buffer) < 6)) //"99:60"
		return (-1);
	int minutes = timeInSeconds / 60;
	int seconds = timeInSeconds % 60;

	std::sprintf(buffer, "%02d:%02d", minutes, seconds);
	return 0;
};

int drawCurtains(int posX, int posY, int height, int width, Color color, int speed)
{
	static int curtain_height = 0;
	int curtain_width = width;
	color.a = 215;
	DrawRectangle(posX, posY, curtain_width, curtain_height, color);

	if (curtain_height < height)
	{
		curtain_height += 1 + speed;
		return (1);
	}
	if (curtain_height > height)
	{
		curtain_height = height;
	}
	return (0);
};

int fadeToBlack(int speed)
{
	static unsigned char fade = 0;
	static int counter = 0;
	Color color = { 0, 0, 0, fade };
	DrawRectangle(GAME_X, GAME_Y, GAME_WIDTH, GAME_HEIGHT, color);
	if (fade == 255)
		return (1);
	counter += 1 + speed;
	if (counter == 60)
	{
		counter = 0;
		if (fade + 60 <= 255)
			fade += 60;
		else
			fade = 255;
	}
	return (0);
};

int fadeFromBlack(int speed)
{
	static unsigned char fade = 255;

	Color color = { 0, 0, 0, fade };
	DrawRectangle(GAME_X, GAME_Y, GAME_WIDTH, GAME_HEIGHT, color);
	if (fade == 0)
		return (1);

	if ((fade - (1 + speed)) >= 0)
		fade -= (1 + speed);
	else
		fade = 0;
	return (0);
};





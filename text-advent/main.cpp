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
		updateState(&state);
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
		state->m_off       = 0.0f;
		state->s_off       = 0.0f;
		state->d_off       = 0.0f;
		state->b_off       = 0.0f;
		state->disposition = 0.0f;
		state->expression  = 0.0f;
		state->movement    = 0.0f;

		state->colors[BACKGROUND]        = BLACK;
		state->colors[DIALOGUE]          = BLACK;
		state->colors[LILGREEN_TEXT]     = GREEN;
		state->colors[NARRATOR_TEXT]     = RED;
		state->colors[WINDOW_BACKGROUND] = BLOOD;
		state->colors[WINDOW_TEXT]       = RED;
		state->colors[ACCENT]            = YELLOW;
		

		state->textures[MARQUIS]     = LoadTexture("./assets/marquis.png");
		state->textures[BACKDROP]    = LoadTexture("./assets/forest_bg.png");
		state->textures[SPRITES]     = LoadTexture("./assets/sprites.png");
		state->textures[DIRECTIONAL] = LoadTexture("./assets/directional.png");
		state->textures[SCORE]       = LoadTexture("./assets/score.png");

		float marquis_source_y       = (0.0f + (32.0f * state->m_off));
		float backdrop_source_x      = (80.0f * (std::fmod(state->b_off, 2.0f)));
		float backdrop_source_y      = (60.0f * (std::floor(state->b_off / 2.0f)));
		float directional_source_y   = (0.0f * (48.0f * state->d_off));
		float lilgreen_base_source_y = (0.0f + (32.0f * state->s_off) + (16.0f * state->disposition));
	       	float lilgreen_anim_source_x = (0.0f + (16.0f * state->expression));
		float lilgreen_anim_source_y = (0.0f + (32.0f * state->s_off) + (16.0f * state->disposition));
		float lilgreen_dir_source_x  = (96.0f + (16.0f * state->movement));
		float lilgreen_dir_source_y  = (0.0f + (32.0f * state->s_off) + (16.0f * state->disposition));
		state->rectangles[MARQUIS_SOURCE]           = { 0.0f, marquis_source_y, 64.0f, 16.0f };
		state->rectangles[BACKDROP_SOURCE]          = { backdrop_source_x, backdrop_source_y, 80.0f, 60.0f };
		state->rectangles[DIRECTIONAL_SOURCE]       = { 0.0f, directional_source_y, 48.0f, 48.0f };
		state->rectangles[LILGREEN_BASE_SOURCE]     = { 0.0f, lilgreen_base_source_y, 16.0f, 16.0f };
		state->rectangles[LILGREEN_ANIMATED_SOURCE] = { lilgreen_anim_source_x, lilgreen_anim_source_y, 16.0f, 16.0f };
		state->rectangles[LILGREEN_DIR_SOURCE]      = { lilgreen_dir_source_x, lilgreen_dir_source_y, 16.0f, 16.0f } ;
		state->rectangles[SCORE_SOURCE]		    = { 0.0f, 0.0f, 80.0f, 60.0f };
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
		}

	}
	*/
}

void updateState(Gamestate *state)
{
	float marquis_source_y       = (0.0f + (32.0f * state->m_off));
	float backdrop_source_x      = (80.0f * (std::fmod(state->b_off, 2.0f)));
	float backdrop_source_y      = (60.0f * (std::floor(state->b_off / 2.0f)));
	float directional_source_y   = (0.0f * (48.0f * state->d_off));
	float lilgreen_base_source_y = (0.0f + (32.0f * state->s_off) + (16.0f * state->disposition));
	float lilgreen_anim_source_x = (0.0f + (16.0f * state->expression));
	float lilgreen_anim_source_y = (0.0f + (32.0f * state->s_off) + (16.0f * state->disposition));
	float lilgreen_dir_source_x  = (96.0f + (16.0f * state->movement));
	float lilgreen_dir_source_y  = (0.0f + (32.0f * state->s_off) + (16.0f * state->disposition));

	state->rectangles[MARQUIS_SOURCE]           = { 0.0f, marquis_source_y, 64.0f, 16.0f };
	state->rectangles[BACKDROP_SOURCE]          = { backdrop_source_x, backdrop_source_y, 80.0f, 60.0f };
	state->rectangles[DIRECTIONAL_SOURCE]       = { 0.0f, directional_source_y, 48.0f, 48.0f };
	state->rectangles[LILGREEN_BASE_SOURCE]     = { 0.0f, lilgreen_base_source_y, 16.0f, 16.0f };
	state->rectangles[LILGREEN_ANIMATED_SOURCE] = { lilgreen_anim_source_x, lilgreen_anim_source_y, 16.0f, 16.0f };
	state->rectangles[LILGREEN_DIR_SOURCE]      = { lilgreen_dir_source_x, lilgreen_dir_source_y, 16.0f, 16.0f } ;
	state->rectangles[SCORE_SOURCE]		    = { 0.0f, 0.0f, 80.0f, 60.0f };

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
	Rectangle marquis_dest = { 256.0f, 200.0f, 768.0f, 192.0f };
	Rectangle sprite_dest = { 350.0f, 415.0f, 128.0f, 128.0f };
	Rectangle marquis_source = state->rectangles[MARQUIS_SOURCE];
	Rectangle sprite_source = state->rectangles[LILGREEN_BASE_SOURCE];
	Texture2D texture = state->textures[MARQUIS];
	Texture2D sprite = state->textures[SPRITES];

	DrawText("Press [SPACE] to play!", 465, 550, 30, state->colors[NARRATOR_TEXT]);
	DrawText("I'm ready for my next adventure!", 433, 420, 30, state->colors[LILGREEN_TEXT]);
	DrawTexturePro(texture, marquis_source, marquis_dest, (Vector2){ 0, 0}, 0, WHITE);
	DrawTexturePro(sprite, sprite_source, sprite_dest, (Vector2){sprite_dest.width /2, sprite_dest.height / 2}, -30, WHITE);
	//DrawRectangleRec(sprite_dest, WHITE);
	if (IsKeyPressed(KEY_SPACE))
		state->gameState = GAME_PLAYING;
};


void game_playing(Gamestate *state)
{

	static float hunger_lvl = 80.0f;
	static Color hunger_bar_color = PINK;

	//---------------------------------MAIN GAME
	Rectangle background_dest = { GAME_X, GAME_Y, GAME_WIDTH, GAME_HEIGHT };
	Rectangle background_source = state->rectangles[BACKDROP_SOURCE];
	Rectangle sprite_dest = { 320.0f, 502.0f, 128.0f, 128.0f };
	Rectangle sprite_source = state->rectangles[LILGREEN_ANIMATED_SOURCE];
	Rectangle directional_dest = {};
	Rectangle directional_source = {};
	Rectangle dialogue = { 440.0f, 480.0f, 260.0f, 55.0f };
	Rectangle narrator = {};
	Rectangle north  =   { 930.0f, 500.0f, 35.0f, 35.0f };
	Rectangle south  =   { 930.0f, 580.0f, 35.0f, 35.0f };
	Rectangle west   =   { 890.0f, 540.0f, 35.0f, 35.0f };
	Rectangle east   =   { 970.0f, 540.0f, 35.0f, 35.0f };
	Rectangle status =   { 240.0f, 100.0f, 215.0f, 50.0f };
	Rectangle hunger =   { 351.0f, 118.0f, hunger_lvl, 10.0f };
	Texture2D texture = state->textures[BACKDROP];
	Texture2D sprite = state->textures[SPRITES];
	DrawTexturePro(texture, background_source, background_dest, (Vector2){0, 0}, 0, WHITE);

	DrawRectangleRec(dialogue, BLACK);
	DrawRectangleRec(north, DARKGRAY);
	DrawRectangleRec(south, DARKGRAY);
	DrawRectangleRec(west, DARKGRAY);
	DrawRectangleRec(east, DARKGRAY);
	DrawRectangleRec(status, BLACK);
	DrawRectangleRec(hunger, hunger_bar_color);
	DrawTexturePro(sprite, sprite_source, sprite_dest, (Vector2){0,0}, 0, WHITE);
	DrawText("Which way should I go?", 455, 500, 20, state->colors[LILGREEN_TEXT]);
	DrawText("HUNGER [           ]", 250, 115, 20, WHITE);
	if (IsKeyPressed(KEY_N))
		hunger_lvl = hunger_lvl - 8;
	if (hunger_lvl <= 64)
		state->b_off = 1.0f;
	if (hunger_lvl <= 48)
	{
		hunger_bar_color = MAROON;
		state->b_off = 2.0f;
	}
	if (hunger_lvl <= 24)
		state->b_off = 3.0f;
	if (hunger_lvl <= 0)
		state->gameState = GAME_OVER;
	if (IsKeyPressed(KEY_SPACE))
		state->gameState = GAME_OVER;
};


void game_over(Gamestate *state)
{
	//---------------------------------GAME OVER
	DrawText("GAME OVER!", 620, 400, 20, state->colors[NARRATOR_TEXT]);
	fadeFromBlack(1);
	if (IsKeyPressed(KEY_SPACE))
		state->gameState = SCORE_BOARD;
	if (IsKeyPressed(KEY_G))
		state->gameState = GAME_PLAYING;
};

void scoreBoard(Gamestate *state)
{
	//---------------------------------SCORE BOARD
	Rectangle score_dest = { GAME_X, GAME_Y, GAME_WIDTH, GAME_HEIGHT };
	Rectangle score_source = state->rectangles[SCORE_SOURCE];
	Texture2D texture = state->textures[SCORE];

	DrawTexturePro(texture, score_source, score_dest, (Vector2){0, 0}, 0, WHITE);

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





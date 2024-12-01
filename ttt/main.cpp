#include "main.h"

//---------------------------------------Main function

int main(int argc, char **argv, char **env) {
	SetTraceLogLevel(LOG_ERROR);
	// Initialize the window
	InitWindow(1280, 800, "Raylib Game");
	InitAudioDevice();
	//--------------------------Init
	Gamestate current_game_state;
	Color colors[MAX_COLORS];
	Texture2D textures[MAX_TEXTURES];
	double frameCount;
	SetTargetFPS(TARGET_FPS);

	init_game(argc, argv, &current_game_state, colors, textures);

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
			splash(&current_game_state, colors, textures, frameCount);
		else if (current_game_state == GAME_PLAYING)
			game_playing(&current_game_state, colors, textures, frameCount);
		else if (current_game_state == GAME_OVER)
			game_over(&current_game_state, colors, textures, frameCount);
		else if (current_game_state == SCORE_BOARD)
			scoreBoard(&current_game_state, colors, textures, frameCount);
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

void init_game(int argc, char **argv, Gamestate *state, Color *gameColors, Texture2D *textures)
{
	//static std::string BASE_PATH = "./assets/";

	if (argc < 2)
	{
		//BASE_PATH = "./assets/"; //filepath to assets directory
		*state = SPLASH;

		gameColors[BACKGROUND] = GRAY;
		gameColors[FOREGROUND] = LIGHTGRAY;
		gameColors[BACKGROUND_TEXT] = DARKGRAY;
		gameColors[FOREGROUND_TEXT] = GRAY;
		gameColors[WINDOW_BACKGROUND] = BLACK;
		gameColors[WINDOW_TEXT] = GREEN;
		

		textures[0] = LoadTexture("./assets/ttt_spritesheet.png");
		/*
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

void splash(Gamestate *state, Color *colors, Texture2D *textures, double frameCount)
{
	//insert splash logic here
	DrawText("SPLASH!", 620, 400, 20, colors[BACKGROUND_TEXT]);
	if (IsKeyPressed(KEY_SPACE))
		*state = GAME_PLAYING;
};
void game_playing(Gamestate *state, Color *colors, Texture2D *textures, double frameCount)
{
	int i;
	char buffer[50];
	char turn_text[8];
	Rectangle recs[9];
	Rectangle player_x = { 0.0f, 0.0f, 16.0f, 16.0f };
	Rectangle player_o = { 16.0f, 0.0f, 16.0f, 16.0f };

	static int textured[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	static int turn = TURN_X;
	static int num_turns = 1;
	const int PADDING = 10;
	const int OFFSET = 150;	
	int row_1_x = BOARD_POSX;
	int row_2_x = BOARD_POSX + OFFSET;
	int row_3_x = row_2_x + OFFSET;
	int col_1_y = BOARD_POSY;
	int col_2_y = BOARD_POSY + OFFSET;
	int col_3_y = col_2_y + OFFSET;
	sprintf(turn_text, "Turn: %d", num_turns);

	recs[0] = (Rectangle){ (float)row_1_x, (float)col_1_y, (float)BLOCK_HEIGHT, (float)BLOCK_WIDTH };
	recs[1] = (Rectangle){ (float)row_2_x, (float)col_1_y, (float)BLOCK_HEIGHT, (float)BLOCK_WIDTH };
	recs[2] = (Rectangle){ (float)row_3_x, (float)col_1_y, (float)BLOCK_HEIGHT, (float)BLOCK_WIDTH };
	recs[3] = (Rectangle){ (float)row_1_x, (float)col_2_y, (float)BLOCK_HEIGHT, (float)BLOCK_WIDTH };
	recs[4] = (Rectangle){ (float)row_2_x, (float)col_2_y, (float)BLOCK_HEIGHT, (float)BLOCK_WIDTH };
	recs[5] = (Rectangle){ (float)row_3_x, (float)col_2_y, (float)BLOCK_HEIGHT, (float)BLOCK_WIDTH };
	recs[6] = (Rectangle){ (float)row_1_x, (float)col_3_y, (float)BLOCK_HEIGHT, (float)BLOCK_WIDTH };
	recs[7] = (Rectangle){ (float)row_2_x, (float)col_3_y, (float)BLOCK_HEIGHT, (float)BLOCK_WIDTH };
	recs[8] = (Rectangle){ (float)row_3_x, (float)col_3_y, (float)BLOCK_HEIGHT, (float)BLOCK_WIDTH };

	//insert game_playing logic here
	//drop shadow
	DrawRectangle(BOARD_POSX + PADDING, BOARD_POSY + PADDING, BOARD_HEIGHT + PADDING, BOARD_WIDTH + PADDING, BLACK);
	//board
	DrawRectangle(BOARD_POSX - PADDING, BOARD_POSY - PADDING, BOARD_HEIGHT + (PADDING * 2), BOARD_WIDTH + (PADDING * 2), DARKGRAY);
	for(i = 0; i <= 8; i++)
	{
		int start_x = 50;
		int start_y = 100;
		int offset_y = 20;
		sprintf(buffer, "textured[%d] = %d", i, textured[i]);
		DrawText(buffer, start_x, (start_y + (i * offset_y)), 20, WHITE);

		DrawRectangleRec(recs[i], GREEN);
		if (textured[i] == 1)
		{
			//DrawRectangleRec(recs[i], WHITE);
			DrawTexturePro(textures[0], player_x, recs[i], (Vector2){ 0, 0}, 0, WHITE);
		}
		else if (textured[i] == 2)
		{
			DrawTexturePro(textures[0], player_o, recs[i], (Vector2){ 0, 0}, 0, WHITE);
		};
	};

	
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && turn == TURN_X) {
            Vector2 mousePos = GetMousePosition();

            // Check if mouse click is within the rectangle
	    for (i = 0; i <= 8; i++)
            	if (CheckCollisionPointRec(mousePos, recs[i]) && (textured[i] == 0)) 
		{
                	 textured[i] = 1;
			 num_turns++;
			 turn = TURN_O;
            	};
        };

	if (turn == TURN_O && num_turns <= 9)
	{
		DrawText(turn_text, 620, 70, 30, RED);
		int new_timer = countDownTimer(3, frameCount, TARGET_FPS);
		if(new_timer == 0)
		{
			for (i = 0; i <= 8; i++)
			{
				if (textured[i] == 0)
				{
					num_turns++;
					textured[i] = 2;
					turn = TURN_X;
					break;
				}
			};
		};
	};
	if (turn == TURN_X && num_turns <= 9) {
		DrawText(turn_text, 620, 70, 30, BLUE);
	};

	if (num_turns > 9)
	{
		static int gate[2] = { 0, 0 };
		//draw!
		if(drawCurtains(GAME_X, GAME_Y, GAME_HEIGHT, GAME_WIDTH, BLUE, 8) == 0)
		{
			DrawText("X Score: ", 620, 250, 30, GREEN);
			if(countDownTimer(1, frameCount, TARGET_FPS) == 0 || gate[0] == 1)
			{
				gate[0] = 1;
				DrawText("Y Score: ", 620, 400, 30, GREEN);
				if(countDownTimer(1, frameCount, TARGET_FPS) == 0 || gate[1] == 1)
				{
					gate[1] = 1;
					DrawText("Press Space!", 620, 550, 30,  GREEN);
				}
			}

		}
		if (IsKeyPressed(KEY_SPACE))
		{
			if(fadeToBlack(1) == 0)
				*state = GAME_OVER;
		}
		return;
	};
};

void game_over(Gamestate *state, Color *colors, Texture2D *textures, double frameCount)
{
	//insert game_over logic here
	fadeFromBlack(1);
	DrawText("GAME OVER!", 620, 400, 20, colors[BACKGROUND_TEXT]);
	if (IsKeyPressed(KEY_SPACE))
		*state = SCORE_BOARD;
	if (IsKeyPressed(KEY_G))
		*state = GAME_PLAYING;
};

void scoreBoard(Gamestate *state, Color *colors, Texture2D *textures, double frameCount)
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
	static double time = -1;
	if (time = -1)
		time = (seconds * target_fps) + frameCount;
	if (time <= frameCount)
	{
		time = -1;
		return (1);
	}
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
	if (countDownSecs == 0)
	{
		countDownSecs = 0;
		targetFrames = 0;
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

int drawCurtains(int posX, int posY, int height, int width, Color color, int speed)
{
	static int curtain_height = 0;
	int curtain_width = width;
	color.a = 128;
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





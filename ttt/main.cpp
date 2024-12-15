#include "main.h"

//---------------------------------------Main function

int main(int argc, char **argv, char **env) {
	//SetTraceLogLevel(LOG_ERROR);
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
		state->gameState = SPLASH;

		state->colors[BACKGROUND] = GRAY;
		state->colors[FOREGROUND] = LIGHTGRAY;
		state->colors[BACKGROUND_TEXT] = DARKGRAY;
		state->colors[FOREGROUND_TEXT] = GRAY;
		state->colors[WINDOW_BACKGROUND] = BLACK;
		state->colors[WINDOW_TEXT] = GREEN;
		state->colors[ACCENT] = BLUE;


		state->textures[MARQUIS] = LoadTexture("ttt/assets/ttt_marquis.png");
		state->textures[SPRITES] = LoadTexture("ttt/assets/ttt_sprites.png");
		state->textures[SCORE] = LoadTexture("ttt/assets/score.png");

		state->rectangles[MARQUIS_SOURCE] = { 0.0f, 0.0f, 64.0f, 16.0f };
		state->rectangles[PLAYER_X] = { 0.0f, 0.0f, 16.0f, 16.0f };
		state->rectangles[PLAYER_O] = { 16.0f, 0.0f, 16.0f, 16.0f };

		init_timers(state->timers, MAX_TIMERS);
		state->frameCount = 0;
	}
	else
	{
		if (std::strcmp(argv[1], "1") == 0)
		{
			//MINICHESS

			state->gameState = SPLASH;

			state->colors[BACKGROUND] = RAYWHITE;
			state->colors[FOREGROUND] = SKYBLUE;
			state->colors[BACKGROUND_TEXT] = DARKGRAY;
			state->colors[FOREGROUND_TEXT] = GRAY;
			state->colors[WINDOW_BACKGROUND] = MAROON;
			state->colors[WINDOW_TEXT] = DARKBLUE;
			state->colors[ACCENT] = RED;


			state->textures[MARQUIS] = LoadTexture("./ttt/assets/ttt_marquis.png");
			state->textures[SPRITES] = LoadTexture("./ttt/assets/ttt_sprites.png");
			state->textures[SCORE] = LoadTexture("./ttt/assets/score.png");

			state->rectangles[MARQUIS_SOURCE] = { 0.0f, 16.0f, 64.0f, 16.0f };
			state->rectangles[PLAYER_X] = { 32.0f, 0.0f, 16.0f, 16.0f };
			state->rectangles[PLAYER_O] = { 48.0f, 0.0f, 16.0f, 16.0f };

			init_timers(state->timers, MAX_TIMERS);
			state->frameCount = 0;
		}
		else if (std::strcmp(argv[1], "2") == 0)
		{
			//TALE OF THE THREE KNIGHTS

			state->gameState = SPLASH;

			state->colors[BACKGROUND] = SKYBLUE;
			state->colors[FOREGROUND] = RAYWHITE;
			state->colors[BACKGROUND_TEXT] = DARKGRAY;
			state->colors[FOREGROUND_TEXT] = GRAY;
			state->colors[WINDOW_BACKGROUND] = DARKPURPLE;
			state->colors[WINDOW_TEXT] = WHITE;
			state->colors[ACCENT] = GOLD;

			state->textures[MARQUIS] = LoadTexture("./ttt/assets/ttt_marquis.png");
			state->textures[SPRITES] = LoadTexture("./ttt/assets/ttt_sprites.png");
			state->textures[SCORE] = LoadTexture("./ttt/assets/score.png");

			state->rectangles[MARQUIS_SOURCE] = { 0.0f, 32.0f, 64.0f, 16.0f };
			state->rectangles[PLAYER_X] = { 0.0f, 16.0f, 16.0f, 16.0f };
			state->rectangles[PLAYER_O] = { 16.0f, 16.0f, 16.0f, 16.0f };

			init_timers(state->timers, MAX_TIMERS);
			state->frameCount = 0;
		}
		else if (std::strcmp(argv[1], "3") == 0)
		{
			//SUPPLY LINES

			state->gameState = SPLASH;
			state->colors[BACKGROUND] = DARKGRAY;
			state->colors[FOREGROUND] = DARKBROWN;
			state->colors[BACKGROUND_TEXT] = DARKGREEN;
			state->colors[FOREGROUND_TEXT] = BROWN;
			state->colors[WINDOW_BACKGROUND] = BLACK;
			state->colors[WINDOW_TEXT] = ORANGE;
			state->colors[ACCENT] = BLACK;

			state->textures[MARQUIS] = LoadTexture("./ttt/assets/ttt_marquis.png");
			state->textures[SPRITES] = LoadTexture("./ttt/assets/ttt_sprites.png");
			state->textures[SCORE] = LoadTexture("./ttt/assets/score.png");

			state->rectangles[MARQUIS_SOURCE] = { 0.0f, 48.0f, 64.0f, 16.0f };
			state->rectangles[PLAYER_X] = { 32.0f, 16.0f, 16.0f, 16.0f };
			state->rectangles[PLAYER_O] = { 48.0f, 16.0f, 16.0f, 16.0f };

			init_timers(state->timers, MAX_TIMERS);
			state->frameCount = 0;

		}
		else
		{
			//DEFAULT

			state->gameState = SPLASH;
			state->colors[BACKGROUND] = GRAY;
			state->colors[FOREGROUND] = LIGHTGRAY;
			state->colors[BACKGROUND_TEXT] = DARKGRAY;
			state->colors[FOREGROUND_TEXT] = GRAY;
			state->colors[WINDOW_BACKGROUND] = BLACK;
			state->colors[WINDOW_TEXT] = GREEN;
			state->colors[ACCENT] = BLUE;

			state->textures[MARQUIS] = LoadTexture("./ttt/assets/ttt_marquis.png");
			state->textures[SPRITES] = LoadTexture("./ttt/assets/ttt_sprites.png");
			state->textures[SCORE] = LoadTexture("./ttt/assets/score.png");

			state->rectangles[MARQUIS_SOURCE] = { 0.0f, 0.0f, 64.0f, 16.0f };
			state->rectangles[PLAYER_X] = { 0.0f, 0.0f, 16.0f, 16.0f };
			state->rectangles[PLAYER_O] = { 16.0f, 0.0f, 16.0f, 16.0f };
			init_timers(state->timers, MAX_TIMERS);
			state->frameCount = 0;


		}

	}
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
	//insert splash logic here
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
	int i;
	double frameCount = state->frameCount;
	static char winner;
	char buffer[50];
	char turn_text[8];
	Rectangle recs[9];
	static int turn = TURN_X;
	static int num_turns = 1;
	static int score_x;
	static int score_o;
	static int is_playing = 1;

	const int winning_combinations[8] =
	{
		0b000000111,
		0b000111000,
		0b111000000,
		0b100100100,
		0b010010010,
		0b001001001,
		0b100010001,
		0b001010100
	};
	static int textured[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	//------------------------------------------------Board generation
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

	DrawRectangle(BOARD_POSX + PADDING, BOARD_POSY + PADDING, BOARD_HEIGHT + PADDING, BOARD_WIDTH + PADDING, BLACK);

	DrawRectangle(BOARD_POSX - PADDING, BOARD_POSY - PADDING, BOARD_HEIGHT + (PADDING * 2), BOARD_WIDTH + (PADDING * 2), state->colors[FOREGROUND]);

	for(i = 0; i <= 8; i++)
	{
		/*int start_x = 50;
		int start_y = 100;
		int offset_y = 20;
		sprintf(buffer, "textured[%d] = %d", i, textured[i]);
		DrawText(buffer, start_x, (start_y + (i * offset_y)), 20, WHITE);
		*/

		DrawRectangleRec(recs[i], state->colors[ACCENT]);
		if (textured[i] == 1)
		{
			DrawTexturePro(state->textures[SPRITES], state->rectangles[PLAYER_X], recs[i], (Vector2){ 0, 0}, 0, WHITE);
		}
		if (textured[i] == 2)
		{
			DrawTexturePro(state->textures[SPRITES], state->rectangles[PLAYER_O], recs[i], (Vector2){ 0, 0}, 0, WHITE);
		};
	};

	// ------------------------------------------------------------Game Logic
	if (is_playing == 0)
	{
		if(drawCurtains(GAME_X, GAME_Y, GAME_HEIGHT, GAME_WIDTH, state->colors[ACCENT], 8) == 0)
		{
			if (winner == 'x')
				DrawText("X Score: 1", 580, 250, 30, state->colors[WINDOW_TEXT]);
			else
				DrawText("X Score: 0", 580, 250, 30, state->colors[WINDOW_TEXT]);


			if(startTimer(&state->timers[1], 1, frameCount, TARGET_FPS) == 0)
			{
				if (winner == 'o')
					DrawText("O Score: 1", 580, 400, 30, state->colors[WINDOW_TEXT]);
				else
					DrawText("O Score: 0", 580, 400, 30, state->colors[WINDOW_TEXT]);

				if(startTimer(&state->timers[2], 1, frameCount, TARGET_FPS) == 0)
				{
					DrawText("Press Space!", 550, 550, 30,  state->colors[WINDOW_TEXT]);
				}
			}

		}
		if (IsKeyPressed(KEY_SPACE))
		{
			init_timers(state->timers, MAX_TIMERS);
			if(fadeToBlack(1) == 0)
				state->gameState = GAME_OVER;
		}
		return;
	}
	if (num_turns == 1)
	{
		score_x = 0b000000000;
		score_o = 0b000000000;
		winner = 'a';
	}
	if (checkWinner(score_x, winning_combinations) == 1)
	{
		num_turns = 9;
		winner = 'x';
		is_playing = 0;
	}
	if (checkWinner(score_o, winning_combinations) == 1)
	{
		num_turns = 9;
		winner = 'o';
		is_playing = 0;
	}
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && turn == TURN_X) {
            Vector2 mousePos = GetMousePosition();

            // Check if mouse click is within the rectangle
	    for (i = 0; i <= 8; i++)
            	if (CheckCollisionPointRec(mousePos, recs[i]) && (textured[i] == 0))
		{
                	 textured[i] = 1;
			 num_turns++;
			 turn = TURN_O;
			 score_x |= (1 << i);
            	};
        };

	if (turn == TURN_O && num_turns <= 9)
	{
		DrawText(turn_text, 620, 70, 30, RED);
		int t = startTimer(&state->timers[0], 2, frameCount, TARGET_FPS);
		if(t == 0)
		{
			for (i = 0; i <= 8; i++)
			{
				if (textured[i] == 0)
				{
					num_turns++;
					textured[i] = 2;
					turn = TURN_X;
					score_o |= (1 << i);
					break;
				}
			};
			resetTimer(&state->timers[0]);
		};
	};
	if (turn == TURN_X && num_turns <= 9) {
		DrawText(turn_text, 620, 70, 30, BLUE);
	};

	if (num_turns > 9)
	{
		is_playing = 0;
	};
};

int checkWinner(int score, const int winner[9])
{
	for (int i = 0; i < 9; i++)
	{
		if((score & winner[i]) == winner[i] && score != 0)
		{
			return (1);
		}
	}
	return (0);
}

void game_over(Gamestate *state)
{
	//insert game_over logic here
	DrawText("GAME OVER!", 620, 400, 20, state->colors[BACKGROUND_TEXT]);
	fadeFromBlack(1);
	if (IsKeyPressed(KEY_SPACE))
		state->gameState = SCORE_BOARD;
	if (IsKeyPressed(KEY_G))
		state->gameState = GAME_PLAYING;
};

void scoreBoard(Gamestate *state)
{
	//insert scoreboard logic here
	Rectangle score_source = { 0.0f, 0.0f, 80.0f, 60.0f };
	Rectangle score_dest = { GAME_X, GAME_Y, GAME_WIDTH, GAME_HEIGHT };
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





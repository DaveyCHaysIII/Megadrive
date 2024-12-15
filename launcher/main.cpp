#include "main.h"

int main(int argc, char **argv, char **env) {

    // ----------------------------------- Init

    InitWindow(1280, 800, "Raylib Game");
    SetTargetFPS(60);
    int i = 0;

    const char* const pong_zero[] = { "./build/pong", "0player", NULL };
    const char* const pong_one[] = { "./build/pong", "1player", NULL };
    const char* const pong_two[] = { "./build/pong", "2player", NULL };
    const char* const tictactoe[] = { "./build/ttt", "0", NULL };
    const char* const minichess[] = { "./build/ttt", "1", NULL };
    const char* const taleofthreeknights[] = { "./build/ttt", "2", NULL };
    const char* const supplylines[] = { "./build/ttt", "3", NULL };

    const char* const *games[] = { pong_zero,
			   pong_one,
			   pong_two,
		  	   tictactoe,
			   minichess,
			   taleofthreeknights,
			   supplylines,
			   NULL };

    Rectangle buttons[MAX_GAMES];
    const char *button_names[MAX_GAMES] = { "Pong - 0",
				 	    "Pong - 1",
				 	    "Pong - 2",
			  	 	    "Tic-Tac-Toe",
				 	    "MiniChess",
				 	    "Tale of the 3 Knights",
				 	    "Supply Lines" };
    for (i = 0; i < MAX_GAMES; i++)
    {
	buttons[i] = (Rectangle){GAME_X, (GAME_Y + ((float)i * 32)), GAME_WIDTH, 32};
    }

    // ------------------------------------ Loop

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(deepgray);
        DrawText("MEGADrive!", 10, 10, 30, GREEN);
	Vector2 mousePosition = GetMousePosition();
	DrawRectangleRec(GAME_REC, BLACK);

	for (i = 0; i < MAX_GAMES; i++)
	{
		bool isHovered = CheckCollisionPointRec(mousePosition, buttons[i]);

		Color rectColor = isHovered ? GREEN : BLACK;
		Color textColor = isHovered ? BLACK : GREEN;
		float x_padding = 2.0f;
		float y_padding = 1.0f;
		DrawRectangleRec(buttons[i], rectColor);
		DrawText(button_names[i],
			 (GAME_X + x_padding),
			 (GAME_Y + (i * 32) + y_padding),
			 30,
			 textColor);
	}

	DrawText(TextFormat("X: %i", (int)mousePosition.x), 1200, 740, 20, DARKGRAY);
        DrawText(TextFormat("Y: %i", (int)mousePosition.y), 1200, 760, 20, DARKGRAY);

        EndDrawing();

	if (IsKeyPressed(KEY_ESCAPE))
		break;
	for (i = 0; i < MAX_GAMES; i++)
	{
		if (CheckCollisionPointRec(mousePosition, buttons[i]))
		{
			if (IsMouseButtonPressed(0))
			{
				launchGame((char* const*)games[i]);
			}
		}
	}
    }
    // -------------------------------- End Loop

    // Close the window
    CloseWindow();
    return 0;
}


void launchGame(char* const* game_args)
{
		pid_t pid = fork();

		if (pid < 0)
		{
			std::cout << "GREVIOUS ERROR!" << std::endl;
			return;
		}
		else if (pid == 0)
		{
			std::cout << "Loading Game " << game_args[0] << std::endl;
			if(execve(game_args[0], game_args, environ) == -1)
			{
				perror("game failed");
			}
		}
		else
		{
			int status;
			waitpid(pid, &status, 0);
		}

}

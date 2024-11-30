#include <raylib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char **argv, char **env) {
    // Initialize the window
    InitWindow(1280, 800, "Raylib Game");

    // Main game loop
    while (!WindowShouldClose()) {
        // Update game state

	Color deepgray = {20, 20, 20, 20};
        // Draw everything
        BeginDrawing();
        ClearBackground(deepgray);
        DrawText("LAUNCHER!", 10, 10, 30, GREEN);

	//mouse coord
	Vector2 mousePosition = GetMousePosition();

	DrawText(TextFormat("X: %i", (int)mousePosition.x), 1200, 740, 20, DARKGRAY);
        DrawText(TextFormat("Y: %i", (int)mousePosition.y), 1200, 760, 20, DARKGRAY);

	// Game Area - Select
	DrawText("PRESS [SPACE] TO LAUNCH GAME", 505, 400, 20, WHITE);

        EndDrawing();

	if (IsKeyPressed(KEY_ESCAPE))
		break;

	if (IsKeyPressed(KEY_SPACE))
	{
		pid_t pid = fork();

		if (pid < 0)
		{
			//error
			continue;
		}
		else if (pid == 0)
		{
			const char *path = "/projects/saves/my_game";
			execve(path, argv, env);
		}
		else
		{
			//parent
			int status;
			waitpid(pid, &status, 0);
		}
	}


    }

    // Close the window
    CloseWindow();
    return 0;
}

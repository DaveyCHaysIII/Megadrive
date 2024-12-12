#include <raylib.h>

int main(int argc, char **argv, char **env) {
    // Initialize the window
    InitWindow(1280, 800, "Raylib Game");

    // Main game loop
    while (!WindowShouldClose()) {
        // Update game state

	Color deepgray = {20, 20, 20, 20};
        // Draw everything
        BeginDrawing();
        ClearBackground(DARKGREEN);
        DrawText("GAME!!", 10, 10, 30, GREEN);

	//mouse coord
	Vector2 mousePosition = GetMousePosition();

	DrawText(TextFormat("X: %i", (int)mousePosition.x), 1200, 740, 20, DARKGRAY);
        DrawText(TextFormat("Y: %i", (int)mousePosition.y), 1200, 760, 20, DARKGRAY);

	// Game Area - Select
	DrawText("THIS IS A GAME", 505, 400, 20, WHITE);

        EndDrawing();

	if (IsKeyPressed(KEY_ESCAPE))
		break;

    }

    // Close the window
    CloseWindow();
    return 0;
}

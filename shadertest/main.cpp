#include "raylib.h"

int main(void) {
    InitWindow(800, 600, "Shader Playground");
    SetTargetFPS(60);

    // Load shaders
    Shader fadeShader = LoadShader(0, "fade.fs");
    int fadeLoc = GetShaderLocation(fadeShader, "fadeFactor");
    float fade = 1.0f;

    Shader tintShader = LoadShader(0, "tint.fs");
    int tintLoc = GetShaderLocation(tintShader, "tintColor");
    float tint[3] = {0.0f, 0.3f, 0.3f};

    Shader invertShader = LoadShader(0, "invert.fs");

    Shader additiveShader = LoadShader(0, "additive.fs");
    int addTintLoc = GetShaderLocation(additiveShader, "tintColor");
    int addStrengthLoc = GetShaderLocation(additiveShader, "strength");
    float addTint[3] = {1.0f, 0.4f, 0.7f}; // pinkish
    float addStrength = 0.5f;

    // Track which shader we’re using
    int currentShader = 0; // 0=fade, 1=tint, 2=invert

    while (!WindowShouldClose()) {
        // --- INPUT ---
        if (IsKeyPressed(KEY_ONE)) currentShader = 0;
        if (IsKeyPressed(KEY_TWO)) currentShader = 1;
        if (IsKeyPressed(KEY_THREE)) currentShader = 2;
	if (IsKeyPressed(KEY_FOUR)) currentShader = 3;

        // Animate fade just for demo
        fade -= 0.01f;
        if (fade < 0.0f) fade = 1.0f;

        // --- DRAW ---
        BeginDrawing();
            ClearBackground(RAYWHITE);

            if (currentShader == 0) {
                BeginShaderMode(fadeShader);
                    SetShaderValue(fadeShader, fadeLoc, &fade, SHADER_UNIFORM_FLOAT);
                    DrawRectangle(100, 100, 600, 400, RED);
                    DrawText("Fade Shader", 250, 300, 30, DARKBLUE);
                EndShaderMode();
            }
            else if (currentShader == 1) {
                BeginShaderMode(tintShader);
                    SetShaderValue(tintShader, tintLoc, tint, SHADER_UNIFORM_VEC3);
                    DrawRectangle(100, 100, 600, 400, RED);
                    DrawText("Tint Shader", 250, 300, 30, DARKBLUE);
                EndShaderMode();
            }
            else if (currentShader == 2) {
                BeginShaderMode(invertShader);
                    DrawRectangle(100, 100, 600, 400, RED);
                    DrawText("Invert Shader", 250, 300, 30, DARKBLUE);
                EndShaderMode();
            }
	    else if (currentShader == 3) {
                BeginShaderMode(additiveShader);
                    SetShaderValue(additiveShader, addTintLoc, addTint, SHADER_UNIFORM_VEC3);
                    SetShaderValue(additiveShader, addStrengthLoc, &addStrength, SHADER_UNIFORM_FLOAT);
                    DrawRectangle(100, 100, 600, 400, RED);
                    DrawText("Additive Tint Shader", 250, 300, 30, DARKBLUE);
                EndShaderMode();
            }

            DrawText("Press 1=Fade, 2=Tint, 3=Invert, 4=Additive", 10, 10, 20, BLACK);
        EndDrawing();
    }

    UnloadShader(fadeShader);
    UnloadShader(tintShader);
    UnloadShader(invertShader);
    CloseWindow();
    return 0;
}

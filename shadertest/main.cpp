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
    float addTint[3] = {1.0f, 0.4f, 0.7f}; // initial color
    float addStrength = 0.7f;

    int currentShader = 0; // 0=fade,1=tint,2=invert,3=additive

    // Timer for retro stepped tint
    float stepTimer = 0.0f;
    int stepIndex = 0;
    float steps[4][3] = {
        {1.0f, 0.4f, 0.7f},  // pink
        {0.4f, 1.0f, 0.4f},  // green
        {0.4f, 0.4f, 1.0f},  // blue
        {1.0f, 1.0f, 1.0f}   // almost white
    };

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();

        // --- INPUT ---
        if (IsKeyPressed(KEY_ONE)) currentShader = 0;
        if (IsKeyPressed(KEY_TWO)) currentShader = 1;
        if (IsKeyPressed(KEY_THREE)) currentShader = 2;
        if (IsKeyPressed(KEY_FOUR)) currentShader = 3;

        // Animate fade for demo
        fade -= 0.01f;
        if (fade < 0.0f) fade = 1.0f;

        // --- Retro stepped additive tint ---
        stepTimer += dt;
        if (stepTimer >= 1.00f) {
            stepTimer = 0.0f;
            stepIndex = (stepIndex + 1) % 4;
            addTint[0] = steps[stepIndex][0];
            addTint[1] = steps[stepIndex][1];
            addTint[2] = steps[stepIndex][2];
        }

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
                    DrawText("Multiply Tint Shader", 250, 300, 30, DARKBLUE);
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

            // Always draw UI text on top
            DrawText("Press 1=Fade, 2=Multiply Tint, 3=Invert, 4=Additive Tint", 10, 10, 20, BLACK);
        EndDrawing();
    }

    // Cleanup
    UnloadShader(fadeShader);
    UnloadShader(tintShader);
    UnloadShader(invertShader);
    UnloadShader(additiveShader);
    CloseWindow();
    return 0;
}

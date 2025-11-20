#include <stdio.h>
#include <stdlib.h>

#include <raylib.h>

int main() {
    InitWindow(800, 600, "raylib test");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLUE);
        DrawText("Raylib работает!", 20, 20, 20, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

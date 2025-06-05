#include "Player.h"
#include "Fish.h"
#include "Fishing.h"
#include <string>
#include <stdio.h>
#include "raylib.h"

Color background = { 0, 50, 80, 255};

int main()
{
    InitWindow(800, 600, "FishingSim");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(background);
            DrawText("TEST", 360, 300, 30, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
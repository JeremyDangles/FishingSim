#include "Player.h"
#include "Fish.h"
#include "Fishing.h"
#include <string>
#include "raylib.h"
#include "TileMap.h"
#include "UserInput.h"
#include "Vector2i.h"
#include <iostream>


Color background = { 0, 50, 80, 255};

int main()
{
    InitWindow(800, 600, "FishingSim");
    SetTargetFPS(60);

    TileMap map(640, 480, 32);
    UserInput input;

    while (!WindowShouldClose())
    {
        Vector2i currentTile = input.getTileUnderMouse(map.getTileSize());
        std::cout << "x: " << currentTile.x << "\ny: " << currentTile.y << std::endl;
        BeginDrawing();
            ClearBackground(background);
            DrawText("TEST", 360, 300, 30, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
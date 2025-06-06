#include "Player.h"
#include "Fish.h"
#include "Fishing.h"
#include <string>
#include "raylib.h"
#include "TileMap.h"
#include "UserInput.h"
#include "Vector2i.h"
#include "TileMapRenderer.h"
#include <iostream>


Color background = { 0, 50, 80, 255};

int main()
{
    InitWindow(800, 600, "FishingSim");
    SetTargetFPS(60);

    TileMap map(20, 32, 32);

int layout[19][24] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
    {1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
    {1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
    {1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
    {1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
    {1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
    {1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
    {1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
    {1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};


    for (int row = 0; row < 20; row++) 
    {
        for (int col = 0; col < 32; col++) 
        {
            int id = layout[row][col];
            bool walkable = (id == 0); // define rules
            map.setTile(row, col, Tile(id, walkable));
        }
    }

    TileMapRenderer mapRenderer(map);
    UserInput input;

    while (!WindowShouldClose())
    {
        Vector2i currentTile = input.getTileUnderMouse(map.getTileSize());
        std::cout << "x: " << currentTile.x << "\ny: " << currentTile.y << std::endl;

        std::cout << "ID: " << map.getTile(currentTile.x, currentTile.y).getIsWalkable() << std::endl;
        BeginDrawing();
            ClearBackground(background);
            //DrawText("TEST", 360, 300, 30, WHITE);
            mapRenderer.drawTiles();
            //mapRenderer.drawGrid();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
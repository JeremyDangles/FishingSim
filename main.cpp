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
#include "PlayerRenderer.h"
#include "PlayerMovement.h"


Color background = { 0, 50, 80, 255};

int main()
{
    InitWindow(768, 608, "FishingSim");
   // SetTargetFPS(60);

    TileMap map(19, 24, 32);

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


    for (int row = 0; row < 19; row++) 
    {
        for (int col = 0; col < 24; col++) 
        {
            int id = layout[row][col];
            bool walkable = (id == 0); // define rules
            map.setTile(row, col, Tile(id, walkable));
        }
    }

    TileMapRenderer mapRenderer(map);
    UserInput input;

    Player player(std::string("Pete"), 0);
    PlayerRenderer playerRenderer;
    playerRenderer.loadTextures();
    PlayerMovement playerMovement;

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        //Vector2i currentTile = input.getTileUnderMouse(map.getTileSize());
        playerMovement.handleInput(player, map, input);
        playerMovement.update(player, deltaTime);
       
        BeginDrawing();
            ClearBackground(MAROON);
            mapRenderer.drawTiles();
            //mapRenderer.drawGrid();
            playerRenderer.drawSpriteAt(player.getPixelPosition());
            DrawFPS(50,50);

        EndDrawing();
        
        
    }


    playerRenderer.unloadTextures();

    CloseWindow();
    return 0;
}
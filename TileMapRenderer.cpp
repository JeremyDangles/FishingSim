// TileMapRenderer.cpp
#include "TileMapRenderer.h"
#include "raylib.h"

TileMapRenderer::TileMapRenderer(TileMap& tileMap) : map(tileMap) {}

void TileMapRenderer::drawGrid()
{
    int rows = map.getRows();
    int columns = map.getColumns();
    int tileSize = map.getTileSize();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            int x = j * tileSize;
            int y = i * tileSize;
            DrawRectangleLines(x, y, tileSize, tileSize, LIGHTGRAY);
        }
    }
 
}
void TileMapRenderer::drawTiles()
{
    int rows = map.getRows();
    int columns = map.getColumns();
    int tileSize = map.getTileSize();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        { 
            Tile& tile = map.getTile(i, j);
            Color colour;
            if (tile.getId() == 0)
            {
                colour = DARKGREEN;
            }
            else
            {
                colour = DARKBLUE;
            }

            DrawRectangle(j * tileSize, i * tileSize, tileSize, tileSize, colour);
        }
    }
}

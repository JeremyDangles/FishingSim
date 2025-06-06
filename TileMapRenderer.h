// TileMapRenderer.h
#pragma once
#include "TileMap.h"

class TileMapRenderer
{
    private:
        TileMap& map;

    public:
        TileMapRenderer(TileMap& tileMap);
        void drawGrid();
        void drawTiles();
};
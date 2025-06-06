// Tilemap.h
#pragma once
#include <vector>
#include "Tile.h"

class TileMap
{
    private:
        int rows;
        int columns;
        int tileSize;
        std::vector<std::vector<Tile>> tiles;

    public:
        TileMap(int rows, int columns, int tileSize);

        Tile& getTile(int row, int column);
        void setTile(int row, int column, const Tile& tile);

        int getRows() const;
        int getColumns() const;
        int getTileSize() const;
        
};
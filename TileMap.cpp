// Tilemap.cpp
#include "TileMap.h"
#include <stdexcept>

TileMap::TileMap(int rows, int columns, int tileSize)
{
    this->rows = rows;
    this->columns = columns;
    this->tileSize = tileSize;
    this->tiles = std::vector<std::vector<Tile>>(rows, std::vector<Tile>(columns, Tile(0, true)));
}

Tile& TileMap::getTile(int row, int column)
{
    if (row >= 0 && row < rows && column >= 0 && column < columns)
    {
        return tiles[row][column];
    }
    throw std::out_of_range("Out of bounds!");
}

void TileMap::setTile(int row, int column, const Tile& tile)
{
    if (row >= 0 && row < rows && column >= 0 && column < columns)
    {
        tiles[row][column] = tile;
    }
    else
    {
        throw std::out_of_range("Out of bounds!");
    }
}

int TileMap::getRows() const
{
    return rows;
}

int TileMap::getColumns() const
{
    return columns;
}

int TileMap::getTileSize() const
{
    return tileSize;
}
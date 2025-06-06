// Tile.cpp
#include <Tile.h>

Tile::Tile(int id, bool walkable)
{
    this->id = id;
    this->walkable = walkable;
}

int Tile::getId() const
{
    return id;
}

bool Tile::getIsWalkable() const
{
    return walkable;
}

void Tile::setId(int id)
{
    this->id = id;
}

void Tile::setIsWalkable(bool walkable)
{
    this->walkable = walkable;
}

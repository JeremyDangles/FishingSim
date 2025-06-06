// Tile.h
#pragma once

class Tile
{
    private:
        int id;
        bool walkable;

    public:
        Tile(int id, bool walkable);
        int getId() const;
        bool getIsWalkable() const;
        void setId(int id);
        void setIsWalkable(bool walkable);
};
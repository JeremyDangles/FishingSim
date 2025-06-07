// Player.h
#pragma once
#include <string>
#include <vector>
#include "Fish.h"
#include "Vector2i.h"
#include "raylib.h"

class Player
{
    private:
        std::string name;
        int money;
        std::vector<Fish> catchBag;
        Vector2i tilePosition;
        Vector2 pixelPosition;

    public:
        Player(const std::string& name, int startingMoney);

        void addFish(const Fish& fish);
        int getMoney() const;
        void addMoney(int amount);
        void display() const;
        int getCatchBagSize();
        void sellOneFish(int index);

        Vector2i getTilePosition() const;
        void setTilePosition(const Vector2i& newPosition);

        Vector2 getPixelPosition() const;
        void setPixelPosition(Vector2 newPosition);
};
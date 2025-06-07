// Player.h
#pragma once
#include <string>
#include <vector>
#include "Fish.h"
#include "Vector2i.h"

class Player
{
    private:
        std::string name;
        int money;
        std::vector<Fish> catchBag;
        Vector2i position;

    public:
        Player(const std::string& name, int startingMoney);
        void addFish(const Fish& fish);
        int getMoney() const;
        void addMoney(int amount);
        void display() const;
        int getCatchBagSize();
        void sellOneFish(int index);
        Vector2i getPosition() const;
        void setPosition(const Vector2i& newPosition);
};
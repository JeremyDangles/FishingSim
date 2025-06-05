// Player.h
#pragma once
#include <string>
#include <vector>
#include "Fish.h"

class Player
{
    private:
        std::string name;
        int money;
        std::vector<Fish> catchBag;

    public:
        Player(const std::string& name, int startingMoney);
        void addFish(const Fish& fish);
        int getMoney() const;
        void addMoney(int amount);
        void display() const;
        int getCatchBagSize();
        void sellFish(int index);
};
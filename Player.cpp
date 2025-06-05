// Player.cpp
#include "Player.h"
#include <iostream>

Player::Player(const std::string& name, int startingMoney)
{
    this->name = name;
    this->money = startingMoney;
}

void Player::addFish(const Fish& fish)
{
    catchBag.push_back(fish);
}

int Player::getMoney() const
{
    return money;
}

void Player::addMoney(int amount)
{
    money += amount;
}

void Player::display() const
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Money: " << money << std::endl;
    
    std::cout << "Fish Caught: " << std::endl;
    for (int i = 0; i < catchBag.size(); i++)
    {
        std::cout << catchBag[i].getSpecies() << ": $" << catchBag[i].getPrice() << std::endl;
    }
}
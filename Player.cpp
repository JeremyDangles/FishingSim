// Player.cpp
#include "Player.h"
#include <iostream>

Player::Player(const std::string& name, int startingMoney)
    : name(name), money(startingMoney), position(12, 8) {} // creates player object at 0, 0

void Player::addFish(const Fish& fish)
{
    if (fish.getSpecies() != "None")
    {
        catchBag.push_back(fish);
    }
    else
    {
        return;
    }
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
    std::cout << "Money: $" << money << std::endl;
    
    std::cout << "Fish Caught: " << std::endl;
    for (int i = 0; i < catchBag.size(); i++)
    {
        std::cout << catchBag[i].getSpecies() << ": $" << catchBag[i].getPrice() << std::endl;
    }
}

int Player::getCatchBagSize()
{
    return catchBag.size();
}

void Player::sellOneFish(int index)
{
    if (index >= 0 && index < catchBag.size())
    {
        money += catchBag[index].getPrice();
        catchBag.erase(catchBag.begin() + index);
    }
}

Vector2i Player::getPosition() const
{
    return position;
}

void Player::setPosition(const Vector2i& newPosition)
{
    position = newPosition;
}
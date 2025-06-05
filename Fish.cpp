// Fish.cpp
#include "Fish.h"
#include <iostream>

Fish::Fish(const std::string& species, int price)
{
    this->species = species;
    this->price = price;
}

std::string Fish::getSpecies() const
{
    return species;
}

int Fish::getPrice() const
{
    return price;
}

void Fish::display() const
{
    std::cout << "Species: " << species << std::endl;
    std::cout << "Price: " << price << std::endl;
}
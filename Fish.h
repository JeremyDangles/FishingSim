// Fish.h
#pragma once
#include <string>

class Fish 
{
    private:
        std::string species;
        int price;

    public:
        Fish(const std::string& species, int price);
        std::string getSpecies() const;
        int getPrice() const;
        void display() const;
};
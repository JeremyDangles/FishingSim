#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

class Fish {
public:
    std::string species;
    int price;
};

class Vessel {
public:
    std::string name;
    int capacity;
};

class Player {
public:
    int money;
    int fishingSessions;
    std::vector<Fish> inventory;
    std::vector<Vessel> vessels;
};

enum class CatchType {
    None,
    SandWhiting,
    KingGeorgeWhiting,
};

void printHeader(std::string string);
void goFishing(Player& player);
CatchType randomCatch();
Fish createFish(CatchType type);
void showFishingResults(Player& player);
int handleMenu(Player& player);

int main()
{
    std::srand(std::time(nullptr)); //Seed RNG once

    printHeader("FISHING BUSINESS SIMULATOR");
    Player player;
    player.money = 0;
    player.fishingSessions = 2;

    while (true)
    {
        int choice = handleMenu(player);

        switch(choice)
        {
            case 1:
                goFishing(player);
                break;
            case 2:
                //goToMarket();
                break;
            case 3:
                showFishingResults(player);
                break;
            case 4:
                //sleep()
                break;
            default:
                std::cout << "Invalid option. Try again." << std::endl;
                break;
        }
    }

    return 0;
}


int handleMenu(Player& player)
{
    int response;
    std::cout << "Please select one of the following options" << std::endl;
    std::cout << "1. Go Fishing (fishing sessions left = " << player.fishingSessions << ")" << std::endl;
    std::cout << "2. Go to the Market" << std::endl;
    std::cout << "3. Show todays catch" << std::endl;
    std::cout << "4. Go to Sleep" << std::endl;
    std::cin >> response;
    std::cout << "\n" << std::endl;
    return response;
}

void printStatus(Player player)
{
    std::cout << "Money $" << player.money << std::endl;

}

void printHeader(std::string string)
{
    int stringLength = string.length();
    std::cout << "\n" << std::endl;
    std::cout << std::string(stringLength, '-') << std::endl;
    std::cout << string<< std::endl;
    std::cout << std::string(stringLength, '-') << std::endl;
    std::cout << "\n" << std::endl;
}

void goFishing(Player& player)
{
    if (player.fishingSessions > 0)
    {
        CatchType caught = randomCatch();
        Fish fish = createFish(caught);

        if (caught == CatchType::None)
        {
            std::cout << "You didnt catch a fish this time.\n" << std::endl;
        }
        else
        {
            std::cout << "Caught a " << fish.species << "! It's worth $" << fish.price << "\n" << std::endl;
            player.inventory.push_back(fish);
        }

        player.fishingSessions--;
    }
    else
    {
        std::cout << "You can't fish anymore today.\n" << std::endl;
        return;
    }
}

void showFishingResults(Player& player)
{
    printHeader("FISH CAUGHT");
    int totalValue = 0;

    for (int i = 0; i < player.inventory.size(); i++)
    {
        std::cout << "1 x " << player.inventory[i].species << ": $" << player.inventory[i].price << std::endl;
        totalValue += player.inventory[i].price;
    }
    std::cout << "\nTotal Value: $" << totalValue << "\n" << std::endl;
}

CatchType randomCatch()
{
    int randomNumber = std::rand() % 10;

    if (randomNumber >= 0 && randomNumber <= 3)
    {
        return CatchType::SandWhiting;
    }
    else if (randomNumber == 4)
    {
        return CatchType::KingGeorgeWhiting;
    }
    else
    {
        return CatchType::None;
    }
}

Fish createFish(CatchType type)
{
    Fish fish;
    switch (type)
    {
        case CatchType::SandWhiting:
            fish.species = "Sand Whiting";
            fish.price = 5;
            break;
        case CatchType::KingGeorgeWhiting:
            fish.species = "King George Whiting";
            fish.price = 10;
            break;
        case CatchType::None:
            fish.species = "";
            fish.price = 0;
            break;
    }
    return fish;
}

void sell(Player& player)
{
    //std::cout << ""
}


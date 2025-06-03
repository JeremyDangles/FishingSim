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

enum class TimeOfDay {
    Morning,
    Afternoon,
    Night
};

void printHeader(std::string string);
void goFishing(Player& player);
CatchType randomCatch();
Fish createFish(CatchType type);
int showFishingResults(Player& player);
int handleMenu(Player& player, TimeOfDay time);
std::string timeOfDayToString(TimeOfDay time);
TimeOfDay passTime(Player& player, TimeOfDay time);
void sell(Player& player, int value);

int fishingSessions = 2;
int day = 1;

int main()
{
    std::srand(std::time(nullptr)); //Seed RNG once

    printHeader("FISHING BUSINESS SIMULATOR");
    Player player;
    player.money = 0;
    player.fishingSessions = fishingSessions;

    TimeOfDay time = TimeOfDay::Morning;

    while (true)
    {
        int choice = handleMenu(player, time);

        switch(choice)
        {
            case 1:
                goFishing(player);
                time = passTime(player, time);
                break;
            case 2:
                sell(player, showFishingResults(player));
                time = passTime(player, time);
                break;
            case 3:
                showFishingResults(player);
                break;
            case 4:
                time = passTime(player, time);
                break;
            default:
                std::cout << "Invalid option. Try again." << std::endl;
                break;
        }
    }
    return 0;
}


int handleMenu(Player& player, TimeOfDay time)
{   
    std::cout << "Day " << day << ": " << timeOfDayToString(time) << std::endl;
    std::cout << "Money: $" << player.money << "\n" << std::endl;
    int response;
    std::cout << "Please select one of the following options" << std::endl;
    std::cout << "1. Go Fishing (fishing sessions left = " << player.fishingSessions << ")" << std::endl;
    std::cout << "2. Go to the Market" << std::endl;
    std::cout << "3. Show catch" << std::endl;
    std::cout << "4. Go to Sleep" << std::endl;
    std::cin >> response;
    std::cout << "\n" << std::endl;
    return response;
}

std::string timeOfDayToString(TimeOfDay time)
{
    switch(time)
    {
        case TimeOfDay::Morning:
            return "Morning";
        case TimeOfDay::Afternoon:
            return "Afternoon";
        case TimeOfDay::Night:
            return "Night";
        default:
            return "Unknown";
    }
}

TimeOfDay passTime(Player& player, TimeOfDay time)
{
    if (time == TimeOfDay::Morning)
    {
        time = TimeOfDay::Afternoon;
    }
    else if (time == TimeOfDay::Afternoon)
    {
        time = TimeOfDay::Night;
    }
    else if (time == TimeOfDay::Night)
    {
        time = TimeOfDay::Morning;
        player.fishingSessions = fishingSessions;
        day++;

    }
    return time;
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

int showFishingResults(Player& player)
{
    printHeader("FISH CAUGHT");
    int totalValue = 0;

    int sandWhitingCaught = 0;
    int sandWhitingValue = 0;

    int kingGeorgeWhitingCaught = 0;
    int kingGeorgeWhitingValue = 0;

    for (int i = 0; i < player.inventory.size(); i++)
    {
        if (player.inventory[i].species == "Sand Whiting")
        {
            sandWhitingCaught++;
            sandWhitingValue += player.inventory[i].price;
        }
        else if (player.inventory[i].species == "King George Whiting")
        {
            kingGeorgeWhitingCaught++;
            kingGeorgeWhitingValue += player.inventory[i].price;
        }
    }

    if (player.inventory.size() > 0)
    {
        if (sandWhitingCaught > 0)
        {
            std::cout << sandWhitingCaught << " x " << "Sand Whiting: $" << sandWhitingValue << std::endl;
        }
        if (kingGeorgeWhitingCaught > 0)
        {
            std::cout << kingGeorgeWhitingCaught << " x " << "King George Whiting: $" << kingGeorgeWhitingValue << std::endl;
        }

        totalValue = sandWhitingValue + kingGeorgeWhitingValue;
    }
    else
    {
        std::cout << "No fish currently in inventory" << std::endl;
    }

    std::cout << "\nTotal Value: $" << totalValue << "\n" << std::endl;
    return totalValue;
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

void sell(Player& player, int value)
{
    player.money += value;
    player.inventory.clear();
}


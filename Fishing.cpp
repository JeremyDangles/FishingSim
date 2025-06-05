#include "Fishing.h"

#include <vector>
#include <cstdlib>
#include <iostream>
#include <time.h>

Fish catchRandomFish()
{
    static bool randomSeeded = false;

    if (!randomSeeded)
    {
        srand(time(NULL));
        randomSeeded = true;
    }

    if (rand() % 2 == 0)
    {
        std::cout << "You didnt catch anything!" << std::endl;
        return Fish("None", 0);
    }

    std::vector<std::pair<std::string, int>> fishOptions =
    {
        {"Herring", 2},
        {"Sand Whiting", 5},
        {"Flathead", 4},
        {"Tailor", 3},
        {"King George Whiting", 8}
    };

    int index = rand() % fishOptions.size();
    std::cout << "You caught a " << fishOptions[index].first << std::endl;
    return Fish(fishOptions[index].first, fishOptions[index].second);
}
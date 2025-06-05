#include "Player.h"
#include "Fish.h"
#include "Fishing.h"
#include <string>
#include <stdio.h>

int main()
{
    Player player(std::string("Pete"), 0);

    for (int i = 0; i < 1000000; i++)
    {
     player.addFish(catchRandomFish());
    }

    printf("\n");

    player.display();
    
    printf("\n");

    int initialMoney = player.getMoney();
    for (int i = player.getCatchBagSize() - 1; i >= 0; i--)
    {
        player.sellFish(i);
    }

    printf("Total Profit: $%i\n\n", (player.getMoney() - initialMoney));
    player.display();
}
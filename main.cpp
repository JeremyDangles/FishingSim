#include "Player.h"
#include "Fish.h"
#include <string>

int main()
{
    Player player(std::string("Pete"), 100);
    player.addMoney(23);
    
    Fish whiting(std::string("Whiting"), 10);
    Fish groper(std::string("Groper"), 40);
    Fish tuna(std::string("Tuna"), 100);
    whiting.display();

    player.addFish(whiting);
    player.addFish(groper);
    player.addFish(tuna);
   
    player.display();
    
}
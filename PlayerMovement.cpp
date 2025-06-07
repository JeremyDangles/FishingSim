// PlayerMovement.cpp
#include "PlayerMovement.h"

void PlayerMovement::handleMovement(Player& player, TileMap& map, const UserInput& input)
{
    Vector2i playerPosition = player.getPosition();

    if (input.keyPressed_W())
    {
        playerPosition.y -= 1;
    }
    if (input.keyPressed_S())
    {
        playerPosition.y += 1;
    }
    if (input.keyPressed_A())
    {
        playerPosition.x -= 1;
    }
    if (input.keyPressed_D())
    {
        playerPosition.x += 1;
    }

    if (map.getTile(playerPosition.y, playerPosition.x).getIsWalkable())
    {
        player.setPosition(playerPosition);
    }
    
}
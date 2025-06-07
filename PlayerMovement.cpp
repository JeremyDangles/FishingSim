// PlayerMovement.cpp
#include "PlayerMovement.h"
#include <cmath>

void PlayerMovement::handleInput(Player& player, TileMap& map, const UserInput& input)
{
    if (isMoving) return;

    Vector2i direction = {0, 0};

    if (input.keyPressed_W()) direction.y = -1;
    if (input.keyPressed_S()) direction.y = 1;
    if (input.keyPressed_A()) direction.x = -1;
    if (input.keyPressed_D()) direction.x = 1;

    if (direction.x != 0 || direction.y != 0)
    {
        // Normalize direction vector
        float length = sqrtf(direction.x * direction.x + direction.y * direction.y);
        float normX = direction.x / length;
        float normY = direction.y / length;

        Vector2i currentTile = player.getTilePosition();
        Vector2i nextTile = { currentTile.x + direction.x, currentTile.y + direction.y };

        // Diagonal walkability checks here (optional)

        if (map.getTile(nextTile.y, nextTile.x).getIsWalkable())
        {
            player.setTilePosition(nextTile);
            moveDirection = { normX, normY };
            targetPixelPosition = 
            {
                nextTile.x * static_cast<float>(tileSize),
                nextTile.y * static_cast<float>(tileSize)
            };
            isMoving = true;
        }
    }
}


void PlayerMovement::update(Player& player, float deltaTime)
{
    if (!isMoving)
    {
        return;
    }

    Vector2 currentPixelPosition = player.getPixelPosition();
    Vector2 velocity = { moveDirection.x * moveSpeed * deltaTime, moveDirection.y * moveSpeed * deltaTime };
    Vector2 nextPosition = { currentPixelPosition.x + velocity.x, currentPixelPosition.y + velocity.y };

    bool arrivedX = (moveDirection.x > 0 && nextPosition.x >= targetPixelPosition.x) || (moveDirection.x < 0 && nextPosition.x <= targetPixelPosition.x);
    bool arrivedY = (moveDirection.y > 0 && nextPosition.y >= targetPixelPosition.y) || (moveDirection.y < 0 && nextPosition.y <= targetPixelPosition.y);

    if ((moveDirection.x != 0 && arrivedX) || moveDirection.y != 0 && arrivedY)
    {
        player.setPixelPosition(targetPixelPosition);
        isMoving = false;
    }
    else
    {
        player.setPixelPosition(nextPosition);
    }
}
// PlayerMovement.h
#pragma once
#include "Player.h"
#include "TileMap.h"
#include "UserInput.h"

class PlayerMovement
{    
    private:
        int tileSize = 32;
        float moveSpeed = 150.0f;
        bool isMoving = false;
        Vector2 targetPixelPosition;
        Vector2 moveDirection;

    public:
        void handleInput(Player& player, TileMap& map, const UserInput& input); 
        void update(Player& player, float deltaTime);
        bool isCurrentlyMoving() const
        {
            return isMoving;
        }

};
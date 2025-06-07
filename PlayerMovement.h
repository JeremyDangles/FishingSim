// PlayerMovement.h
#pragma once
#include "Player.h"
#include "TileMap.h"
#include "UserInput.h"

class PlayerMovement
{    
    public:
        void handleMovement(Player& player, TileMap& map, const UserInput& input); 

};
// UserInput.h
#pragma once
#include "raylib.h"
#include <utility>
#include "Vector2i.h"

class UserInput
{
    public:
        Vector2i getTileUnderMouse(int tileSize);
};
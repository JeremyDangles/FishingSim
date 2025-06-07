// UserInput.h
#pragma once
#include "raylib.h"
#include <utility>
#include "Vector2i.h"

class UserInput
{
    public:
        Vector2i getTileUnderMouse(int tileSize);
        bool leftMouseClick();
        
        bool keyPressed_W();
        bool keyPressed_A();
        bool keyPressed_S();
        bool keyPressed_D();
};
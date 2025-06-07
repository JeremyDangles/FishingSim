// UserInput.h
#pragma once
#include "raylib.h"
#include <utility>
#include "Vector2i.h"

class UserInput
{
    public:
        Vector2i getTileUnderMouse(int tileSize) const;
        bool leftMouseClick() const;

        bool keyPressed_W() const;
        bool keyPressed_A() const;
        bool keyPressed_S() const;
        bool keyPressed_D() const;
};
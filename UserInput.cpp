// UserInput.cpp
#include "UserInput.h"

Vector2i UserInput::getTileUnderMouse(int tileSize)
{
    Vector2 mouse = GetMousePosition();

    int column = static_cast<int>(mouse.x) / tileSize;
    int row = static_cast<int>(mouse.y) / tileSize;

    return { row, column };
}

bool leftMouseClick()
{
    return IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
}
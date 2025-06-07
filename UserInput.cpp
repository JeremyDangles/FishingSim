// UserInput.cpp
#include "UserInput.h"

Vector2i UserInput::getTileUnderMouse(int tileSize) const
{
    Vector2 mouse = GetMousePosition();

    int column = static_cast<int>(mouse.x) / tileSize;
    int row = static_cast<int>(mouse.y) / tileSize;

    return { column, row };
}

bool UserInput::leftMouseClick() const
{
    return IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
}

bool UserInput::keyPressed_W() const
{
    return IsKeyDown(KEY_W);
}

bool UserInput::keyPressed_A() const
{
    return IsKeyDown(KEY_A);
}

bool UserInput::keyPressed_S() const
{
    return IsKeyDown(KEY_S);
}

bool UserInput::keyPressed_D() const
{
    return IsKeyDown(KEY_D);
}
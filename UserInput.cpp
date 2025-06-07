// UserInput.cpp
#include "UserInput.h"

Vector2i UserInput::getTileUnderMouse(int tileSize) const
{
    Vector2 mouse = GetMousePosition();

    int column = static_cast<int>(mouse.x) / tileSize;
    int row = static_cast<int>(mouse.y) / tileSize;

    return { row, column };
}

bool UserInput::leftMouseClick() const
{
    return IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
}

bool UserInput::keyPressed_W() const
{
    return IsKeyPressed(KEY_W);
}

bool UserInput::keyPressed_A() const
{
    return IsKeyPressed(KEY_A);
}

bool UserInput::keyPressed_S() const
{
    return IsKeyPressed(KEY_S);
}

bool UserInput::keyPressed_D() const
{
    return IsKeyPressed(KEY_D);
}
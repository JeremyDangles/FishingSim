// PlayerRenderer.cpp
#include "PlayerRenderer.h"
#include "raylib.h"
#include "Vector2i.h"

void PlayerRenderer::drawSprite(const Player& player)
{
    Vector2i position = player.getPosition();
    int size = 32;

    DrawTexture(sprite, position.x * size, position.y * size, WHITE);
}

void PlayerRenderer::loadTextures()
{
    Image spriteImage = LoadImage("playerSprite.png");
    sprite = LoadTextureFromImage(spriteImage);
    UnloadImage(spriteImage);
    textureLoaded = true;
}

void PlayerRenderer::unloadTextures()
{
    if (textureLoaded) 
    {
        UnloadTexture(sprite);
        textureLoaded = false;
    }
}
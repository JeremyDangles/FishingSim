// PlayerRenderer.cpp
#include "PlayerRenderer.h"
#include "raylib.h"
#include "Vector2i.h"

void PlayerRenderer::drawSpriteAt(Vector2 pixelPosition)
{
    int tileSize = 32;
    float yOffset = tileSize / 4.0f;
    DrawTexture(sprite, static_cast<int>(pixelPosition.x), static_cast<int>(pixelPosition.y - yOffset), WHITE);
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
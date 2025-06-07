// PlayerRenderer.h
#pragma once
#include "Player.h"
#include "raylib.h"

class PlayerRenderer
{
    private:
        Texture2D sprite;
        bool textureLoaded = false;

    public:
        void drawSpriteAt(Vector2 pixelPosition);
        void loadTextures();
        void unloadTextures();
};
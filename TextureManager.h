#pragma once
#include "Game.h"

class TextureManager {
public:
    static SDL_Texture *loadTexture(const char *filename);

    static void drawTexture(SDL_Texture *_texture, SDL_Rect destRect);
};

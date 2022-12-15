#ifndef INC_2D_GAME_SDL2_TEXTUREMANAGER_H
#define INC_2D_GAME_SDL2_TEXTUREMANAGER_H

#include "Game.h"

class TextureManager {
public:
    static SDL_Texture *loadTexture(const char *filename);

    static void drawTexture(SDL_Texture *_texture, SDL_Rect destRect);
};


#endif //INC_2D_GAME_SDL2_TEXTUREMANAGER_H

#ifndef INC_2D_GAME_SDL2_TEXTUREMANAGER_H
#define INC_2D_GAME_SDL2_TEXTUREMANAGER_H

#include "Game.h"

class TextureManager {
public:
    static SDL_Texture *LoadTexture(const char *filename, SDL_Renderer *renderer);
};


#endif //INC_2D_GAME_SDL2_TEXTUREMANAGER_H

#include "TextureManager.h"

SDL_Texture *TextureManager::LoadTexture(const char *filename, SDL_Renderer *renderer) {
    SDL_Surface *image = IMG_Load(filename);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
    
    return texture;
}

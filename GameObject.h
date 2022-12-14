//
// Created by youssef on 12/15/22.
//

#ifndef INC_2D_GAME_SDL2_GAMEOBJECT_H
#define INC_2D_GAME_SDL2_GAMEOBJECT_H

#include "Game.h"

class GameObject {
public:
    GameObject(const char *_textureFilename, SDL_Renderer *_renderer, int _x, int _y, int _width,
               int _height);

    ~GameObject();
    
    void update();
    
    void render();

    void destroy();

private:
    int xPos, yPos;
    SDL_Texture *texture;
    SDL_Rect destRect;
    SDL_Renderer *renderer;
};


#endif //INC_2D_GAME_SDL2_GAMEOBJECT_H

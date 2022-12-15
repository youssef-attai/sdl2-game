#pragma once

#include "Game.h"

class TileMap {
public:
    TileMap();

    ~TileMap();

    void loadMap(int _map[20][25]);

    void drawMap();

private:
    SDL_Rect destRect;
    SDL_Texture *water, *dirt, *grass;
    int map[20][25];
};

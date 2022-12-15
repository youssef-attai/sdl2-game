#ifndef INC_2D_GAME_SDL2_TILEMAP_H
#define INC_2D_GAME_SDL2_TILEMAP_H

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


#endif //INC_2D_GAME_SDL2_TILEMAP_H

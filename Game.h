#ifndef INC_2D_GAME_SDL2_GAME_H
#define INC_2D_GAME_SDL2_GAME_H

#include "SDL2/SDL.h"
#include <iostream>

class Game {

public:
    Game();

    ~Game();

    void init(const char *_title, int _xPos, int _yPos, int _width, int _height, bool _fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    
    bool running();
    
private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
};


#endif //INC_2D_GAME_SDL2_GAME_H

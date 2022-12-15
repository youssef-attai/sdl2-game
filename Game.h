#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>

class Game {

public:
    Game();

    ~Game();

    void init(const char *_title, int _xPos, int _yPos, int _width, int _height);

    void handleEvent();

    void update();

    void render();

    void clean();

    bool running() const;

    static SDL_Renderer *renderer;

private:
    bool isRunning;
    SDL_Window *window;
};
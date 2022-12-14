//
// Created by youssef on 12/14/22.
//

#include "Game.h"

Game::Game() {

}

Game::~Game() {

}

void Game::init(const char *_title, int _xPos, int _yPos, int _width, int _height, bool _fullscreen) {
//    Initialize all SDL subsystems

//  If SDL subsystems did not initialize successfully
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
//        Set game state to "not running" and return
        isRunning = false;
        return;
    }

    std::cout << "SDL subsystems initialized" << '\n';

//        Create the window
    window = SDL_CreateWindow(
            _title,
            _xPos,
            _yPos,
            _width,
            _height,
            (_fullscreen ? SDL_WINDOW_FULLSCREEN : 0)
    );

//    Check if the window is created successfully
    if (window) std::cout << "Window created" << '\n';

//    Create the renderer for the created window
//    index=-1 means initialize the first rendering driver that supports the given flags
    renderer = SDL_CreateRenderer(window, -1, 0);

//    Check if the renderer is created successfully
    if (renderer) {
        std::cout << "Renderer created" << '\n';

//        Draw a white screen initially
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    }


//    Set the game running state to "running"
    isRunning = true;
}

void Game::handleEvent() {
//    Load the next event from the event queue into the variable event
    SDL_Event event;
    SDL_PollEvent(&event);

//    Check the type of the event
    switch (event.type) {
//        If it was a quit/exit event
        case SDL_QUIT:
//            Set game state to "not running"
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update() {

}

void Game::render() {
    SDL_RenderClear(renderer);

    /* Here goes whatever we would like to render */

    SDL_RenderPresent(renderer);
}

void Game::clean() {

}

bool Game::running() {
    return false;
}

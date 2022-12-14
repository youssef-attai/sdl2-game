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
    if (renderer) std::cout << "Renderer created" << '\n';

//    Set the game running state to "running"
    isRunning = true;
}

void Game::handleEvents() {

}

void Game::update() {

}

void Game::render() {

}

void Game::clean() {

}

bool Game::running() {
    return false;
}

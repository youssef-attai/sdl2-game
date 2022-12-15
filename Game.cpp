#include "Game.h"
#include "utils.h"
#include "GameObject.h"

//  The player;
GameObject *player;

Game::Game() {}

Game::~Game() {}

void Game::init(const char *_title, int _xPos, int _yPos, int _width, int _height) {
//    Initialize all SDL subsystems

//  If SDL subsystems did not initialize successfully
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
//        Set game state to "not running" and return
        isRunning = false;
        return;
    }

    std::cout << "SDL subsystems initialized" << '\n';

//        Create the window
    window = SDL_CreateWindow(_title, _xPos, _yPos, _width, _height, 0);

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

//    Create the player texture 
    player = new GameObject(asset("mario"), renderer, 0, 0, 32, 64);
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
    player->update();
}

void Game::render() {
    SDL_RenderClear(renderer);
    player->render();
    SDL_RenderPresent(renderer);
}

void Game::clean() {
//    Free all allocated memory, destroy all objects
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    player->destroy();
    SDL_Quit();

    std::cout << "Game cleaned" << '\n';
}

bool Game::running() const {
    return isRunning;
}

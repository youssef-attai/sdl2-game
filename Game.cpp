#include "Game.h"

//  The player texture;
SDL_Texture *playerTexture;

Game::Game() {

}

Game::~Game() {

}

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

//    Create a surface for the player
    SDL_Surface *playerImage = IMG_Load("../assets/mario.png");

//    Create the player texture from the surface with the player's PNG
    playerTexture = SDL_CreateTextureFromSurface(renderer, playerImage);

//    Delete the surface after use
    SDL_FreeSurface(playerImage);
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

    SDL_RenderCopy(renderer, playerTexture, nullptr, nullptr);

    SDL_RenderPresent(renderer);
}

void Game::clean() {
//    Free all allocated memory, destroy all objects
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(playerTexture);
    SDL_Quit();

    std::cout << "Game cleaned" << '\n';
}

bool Game::running() const {
    return isRunning;
}

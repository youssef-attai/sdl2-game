#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char *_textureFilename, SDL_Renderer *_renderer, int _x, int _y, int _width,
                       int _height) {
    renderer = _renderer;
    texture = TextureManager::LoadTexture(_textureFilename, renderer);

    xPos = _x;
    yPos = _y;
    destRect.w = _width;
    destRect.h = _height;
}

GameObject::~GameObject() {

}

void GameObject::update() {
    xPos++;
    yPos++;
}

void GameObject::render() {
    destRect.x = xPos;
    destRect.y = yPos;
    
    SDL_RenderCopy(renderer, texture, nullptr, &destRect);
}

void GameObject::destroy() {
    SDL_DestroyTexture(texture);
}

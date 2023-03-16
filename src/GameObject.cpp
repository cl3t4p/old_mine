#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const std::string& textureSheet, int x, int y) {
    texture = TextureManager::loadTexture(textureSheet);
    xpos = x;
    ypos = y;
}

GameObject::~GameObject() = default;

void GameObject::update() {

    xpos++;
    ypos++;


    //Render stuff
    srcRect.h = 8;
    srcRect.w = 8;
    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * 4;
    destRect.h = srcRect.h * 4;

}

void GameObject::render() {
    SDL_RenderCopy(Game::renderer,texture,&srcRect,&destRect);
}



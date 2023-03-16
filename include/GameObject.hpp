#pragma once
#include "Game.hpp"
class GameObject{

private:
    int xpos{};
    int ypos{};
    SDL_Texture* texture{};
    SDL_Rect srcRect{},destRect{};
public:
    GameObject(const std::string& textureSheet, int x, int y);
    ~GameObject();

    void update();
    void render();

};
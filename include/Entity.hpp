#pragma once
#include "Game.hpp"
class Entity{

private:

    int xpos{};
    int ypos{};
    SDL_Texture* texture{};
    SDL_Rect srcRect{},destRect{};
public:
    Entity(const std::string& textureSheet, int x, int y);
    ~Entity();

    void update();
    void render();

};
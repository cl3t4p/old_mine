#pragma once
#include "Game.hpp"

class TextureManager{
private:
public:
    static SDL_Texture* loadTexture(const std::string& fileName);
    static void draw(SDL_Texture* texture,SDL_Rect src,SDL_Rect dst);
};


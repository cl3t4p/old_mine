#pragma once
#include <SDL.h>
#include <string>
#include "Entity.hpp"

class RenderWindow{
public:
    RenderWindow(const std::string& title, int w, int h);
    SDL_Texture* loadTexture(const std::string& filePath);
    void display();
    void render(Entity& texture,int mult);
    void clear();
    void cleanUp();
    void drawBackground(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};

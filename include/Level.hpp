#pragma once
#include "Game.hpp"

class Level{
private:
    SDL_Rect src,dest;
    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;

    int map[20][25];
public:
    Level();
    ~Level();
    void loadMap(int array[20][25]);
    void drawMap();
};
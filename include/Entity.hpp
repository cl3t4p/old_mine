#pragma once

#include <SDL.h>
#include <SDL_image.h>


class Entity{
    public:
        Entity(float x,float y,SDL_Texture* texture);
        float getX() const;
        float getY() const;
        SDL_Texture *getTexture() const;
        SDL_Rect getCurrentFrame() const;
    private:
        float x,y;
        SDL_Rect currentFrame;
public:



private:
    SDL_Texture* texture;
};
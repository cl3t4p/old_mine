#pragma once
#include "Component.h"
#include <SDL2/SDL.h>
#include "TextureManager.hpp"


class SpriteComponent : public Component{

private:
    TransformComponent *position;
    SDL_Texture *texture;
    SDL_Rect srcRect,dstRect;
    int static const SRC = 16;
    int static const DST = 32;

public:
    SpriteComponent() = default;
    SpriteComponent(const char* path){
        setTex(path);
    }

    void setTex(const char* path){
        texture = TextureManager::loadTexture(path);
    }
    void setTexture(SDL_Texture* texture){
        SpriteComponent::texture = texture;
    }

    void init() override{
        position = &owner->getComponent<TransformComponent>();

        srcRect.x = srcRect.y = 0;
        srcRect.w = srcRect.h = SRC;
        dstRect.w = dstRect.h = DST;
    }
    void update() override{
        dstRect.x = position->x();
        dstRect.y = position->y();
    }
    void draw() override{
        TextureManager::draw(texture,srcRect,dstRect);
    }
};

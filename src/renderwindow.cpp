
#include <SDL.h>
#include <SDL_image.h>
#include "RenderWindow.hpp"
#include "Entity.hpp"

RenderWindow::RenderWindow(const std::string& title, int w, int h)
:window{nullptr},renderer{nullptr}
{
    window = SDL_CreateWindow(
            title.c_str(),
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            w,
            h,SDL_WINDOW_SHOWN);
    if(window == nullptr){
        printf("Window init failed!!!\n%s\n",SDL_GetError());
    }
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::loadTexture(const std::string& filePath) {
    SDL_Texture* texture = nullptr;
    texture = IMG_LoadTexture(renderer,filePath.c_str());
    if(texture == nullptr)
        printf("Imagine loading failed!!!\n%s\n",SDL_GetError());
    return texture;
}

void RenderWindow::render(Entity& entity,int mult) {
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = 8;
    src.h = 8;
    SDL_Rect dst;
    dst.x = entity.getX()*mult;
    dst.y = entity.getY()*mult;
    dst.w = entity.getCurrentFrame().w * mult;
    dst.h = entity.getCurrentFrame().h * mult;

    


    SDL_RenderCopy(renderer, entity.getTexture(), &src, &dst);
}

void RenderWindow::display(){
    SDL_RenderPresent(renderer);
}

void RenderWindow::drawBackground(Uint8 r,Uint8 g,Uint8 b,Uint8 a){
    SDL_SetRenderDrawColor(renderer,r,g,b,a);
}

void RenderWindow::clear() {
    SDL_RenderClear(renderer);
}

void RenderWindow::cleanUp() {
    SDL_DestroyWindow(window);
}


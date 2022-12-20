#include <SDL.h>
#include "Game.hpp"

Game *game = nullptr;



int main(int argc,char* args[]) {
    game = new Game();
    game->init("Old Mine",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,640, false);


    const int FPS = 144;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;

    while (game->isRunning()){
        frameStart = SDL_GetTicks();
        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime){
            SDL_Delay(frameDelay-frameTime);
        }
    }
    game->clean();

    return 0;
}

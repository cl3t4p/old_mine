#include <SDL.h>
#include "renderwindow.hpp"
#include "Entity.hpp"
#include "Game.hpp"

int main(int argc,char* args[]) {
    Game game;
    RenderWindow window("Test", 800, 600);

    //Game lood
    game.init();

    SDL_Event event;
    while (game.isGameRunning()){
        game.loop();
        //Checking inputs
        while (SDL_PollEvent(&event)){
            if(event.type==SDL_QUIT)
                gameRunning = false;
        }
    }



    window.cleanUp();
    SDL_Quit();
    return 0;
}

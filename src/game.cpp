#include "Game.hpp"

void Game::init() {

}

void Game::loop() {
    SDL_Event event = pullEvent();
    if(event.type==SDL_QUIT)
        close();

}

void Game::close() {
    gameRunning = false;
}

SDL_Event Game::pullEvent(){
    SDL_Event event;
    SDL_PollEvent(&event);
    return event;

}

bool Game::isGameRunning() const {
    return gameRunning;
}



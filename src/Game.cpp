#include "Game.hpp"
#include "Entity.hpp"
#include "Level.hpp"

Entity* player;
Entity* enemy;
Level* level;


SDL_Renderer* Game::renderer = nullptr;

Game::Game() = default;
Game::~Game() = default;

void Game::init(const std::string& title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;
    if(fullscreen)
        flags = SDL_WINDOW_FULLSCREEN;

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "Subsystems Initialised!..." << std::endl;
        window = SDL_CreateWindow(title.c_str(),xpos,ypos,width,height,flags);
        if(window){
            std::cout << "Window created!" << std::endl;
        }

        renderer = SDL_CreateRenderer(window,-1,0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer,255,255,255,255);
            std::cout << "Renderer created!" << std::endl;
        }
        gameRunning = true;
    }else{
        gameRunning = false;
        std::cout << "[ERROR] SDL_INIT : " << SDL_GetError() << std::endl;
    }

    player = new Entity("res/player/player.png", 0, 0);
    enemy = new Entity("res/player/enemy.png", 50, 50);
    level = new Level();
}


void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    //Key reading
    switch (event.type) {
        case SDL_QUIT:
            gameRunning = false;
            break;
        default:
            break;
    }
}

void Game::update() {
    cnt++;
    player->update();
    enemy->update();

    std::cout << "Count : " << cnt << std::endl;
}

void Game::render() {
    SDL_RenderClear(renderer);
    //Stuff to render
    level->drawMap();
    player->render();
    enemy->render();

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}

bool Game::isRunning() const {
    return gameRunning;
}
#include "Game.hpp"
#include "Level.hpp"
#include "ECS/Component.h"



Level* level;


SDL_Renderer* Game::renderer = nullptr;


Manager manager;
Entity& player(manager.addEntity());


Game::Game() = default;
Game::~Game() = default;

void Game::init(const std::string& title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;
    if(fullscreen)
        flags = SDL_WINDOW_FULLSCREEN;

    //SLD Initiation
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

    //Variable stuff
    level = new Level();
    //ECS
    player.addComponent<TransformComponent>(0,0);
    player.addComponent<SpriteComponent>("res/player/player.png");
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
    manager.refresh();
    manager.update();

    if(player.getComponent<TransformComponent>().x() > 100){
        player.getComponent<SpriteComponent>().setTex("res/player/enemy.png");
    }
    player.update();
}

void Game::render() {
    SDL_RenderClear(renderer);
    //Stuff to render
    level->drawMap();

    player.draw();
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
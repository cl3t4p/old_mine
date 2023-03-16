
#ifndef Game_hpp
#define Game_hpp
#include <SDL.h>
#include <string>
#include <iostream>
#include <SDL_image.h>
class Game{
private:
    bool gameRunning{};
    SDL_Window *window{};
    int cnt = 0;

public:
    Game();
    ~Game();
    void init(const std::string& title,int xpos,int ypos,int width,int height,bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    bool isRunning() const;
    static SDL_Renderer* renderer;
};

#endif /* Game_hpp */

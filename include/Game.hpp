#pragma once
#include <SDL.h>
class Game{
private:
    bool gameRunning = true;
public:
    bool isGameRunning() const;
    void init();
    void loop();
    void close();
    static SDL_Event pullEvent();
};
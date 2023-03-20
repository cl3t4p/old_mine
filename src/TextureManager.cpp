
#include "TextureManager.hpp"

SDL_Texture* TextureManager::loadTexture(const std::string& fileName) {
#ifdef FALSE
    SDL_Surface* tmpSurface = IMG_Load(fileName.c_str());
    if(tmpSurface == nullptr){
        std::cout << "error while loading res file" << std::endl;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer,tmpSurface);
#endif
    SDL_Texture* texture = IMG_LoadTexture(Game::renderer,fileName.c_str());
    if(texture == nullptr){
        std::cout << SDL_GetError() << std::endl;
    }
    //SDL_FreeSurface(tmpSurface);
    return texture;
}

void TextureManager::draw(SDL_Texture *texture, SDL_Rect src, SDL_Rect dst) {
    SDL_RenderCopy(Game::renderer,texture,&src,&dst);
}


#include "TextureManager.hpp"

SDL_Texture* TextureManager::loadTexture(const std::string& fileName) {
    SDL_Surface* tmpSurface = IMG_Load(fileName.c_str());
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer,tmpSurface);
    SDL_FreeSurface(tmpSurface);
    return texture;
}

void TextureManager::draw(SDL_Texture *texture, SDL_Rect src, SDL_Rect dst) {
    SDL_RenderCopy(Game::renderer,texture,&src,&dst);
}

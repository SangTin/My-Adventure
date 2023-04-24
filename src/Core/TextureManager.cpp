#include <iostream>
#include <Core/TextureManager.hpp>
#include <Core/Game.hpp>

/**
 * Load texture from given path
 * \param f_path the path on the filesystem to load an image from.
*/
SDL_Texture* TextureManager::load_texture(const char* f_path){
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(Game::renderer, f_path);
    if (texture == NULL){
        std::cout << "Failed to load texture " << f_path << "!SDL_image Error: " << IMG_GetError() << '\n';
    }
    return texture;
}

/**
 * Draw texture to the game renderer
 * \param texture the source texture
*/
void TextureManager::draw(SDL_Texture* texture){
    SDL_Rect src;
    src.x = src.y = 0;
    SDL_QueryTexture(texture, NULL, NULL, &src.w, &src.h);
    SDL_RenderCopy(Game::renderer, texture, &src, &src);
}

/**
 * Draw texture to the game renderer with given informations
 * \param texture the source texture
 * \param src the source SDL_Rect structure or NULL for the entire texture
 * \param dst the destination SDL_Rect structure or NULL for the entire rendering target
*/
void TextureManager::draw(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dst, SDL_RendererFlip flip){
    SDL_RenderCopyEx(Game::renderer, texture, src, dst, 0, nullptr, flip);
}
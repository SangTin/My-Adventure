#pragma once
#include <SDL2/SDL.h>

class TextureManager{
    public:
        static SDL_Texture* load_texture(const char* path);
        static void draw(SDL_Texture* texture);
        static void draw(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dst, SDL_RendererFlip flip = SDL_FLIP_NONE);
};
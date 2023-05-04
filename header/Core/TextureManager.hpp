#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class TextureManager{
    public:
        static SDL_Texture* load_texture(const char* path);
        static SDL_Texture* load_texture(SDL_Surface* surface);

        static void draw(SDL_Texture* texture);
        static void draw(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dst, SDL_RendererFlip flip = SDL_FLIP_NONE);
};
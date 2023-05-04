#pragma once
#include <SDL2/SDL.h>

struct TTF_Text{
    SDL_Texture* texture;
    SDL_Rect src;

    TTF_Text(SDL_Texture* texture = nullptr, int w = 0, int h = 0){
        this->texture = texture;
        src = {0, 0, w, h};
    }

    ~TTF_Text(){
        SDL_DestroyTexture(texture);
    }
};

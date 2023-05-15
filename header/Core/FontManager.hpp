#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Base.hpp"
#include <string>

struct TTF_Text{
    std::string text;
    SDL_Texture* texture;
    SDL_Rect src;

    TTF_Text(){}

    TTF_Text(const std::string text, SDL_Texture* texture = nullptr, int w = 0, int h = 0){
        this->text = text;
        this->texture = texture;
        src = {0, 0, w, h};
    }

    ~TTF_Text(){
        SDL_DestroyTexture(texture);
    }
};

class FontManager{
    public:
        static TTF_Font* load_font(const char* f_path, int size = 18);
        static TTF_Text* load_text(const std::string text, int width, int size, TTF_Font* font = nullptr, SDL_Color color = Base::defaultColor);
        static void draw_text(TTF_Text* text, SDL_Rect* dst);
        static void draw_text(const std::string text, SDL_Rect* dst, int size, TTF_Font* font = nullptr, SDL_Color color = Base::defaultColor);
};
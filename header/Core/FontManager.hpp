#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "TTF_Text.hpp"
#include "Base.hpp"

class FontManager{
    public:
        static TTF_Font* load_font(const char* f_path, int size = 18);
        static TTF_Text load_text(TTF_Font* font, const char* text, SDL_Color color = Base::defaultColor);
        static void draw_text(TTF_Text* text, SDL_Rect* dst);
        static void draw_text(TTF_Font* font, const char* text, SDL_Rect* dst, SDL_Color color = Base::defaultColor);
        static void draw_text(const char* text, SDL_Rect* dst, SDL_Color color = Base::defaultColor);
};
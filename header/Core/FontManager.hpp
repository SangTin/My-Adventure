#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "TTF_Text.hpp"

class FontManager{
    public:
        static TTF_Font* load_font(const char* f_path, int size);
        static TTF_Text load_text(TTF_Font* font, const char* text, SDL_Color color);
        static void draw_text(TTF_Text* text, SDL_Rect* dst);
        static void draw_text(TTF_Font* font, const char* text, SDL_Color color, SDL_Rect* dst);
};
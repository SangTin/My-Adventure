#include <iostream>
#include <Core/FontManager.hpp>
#include <Core/TextureManager.hpp>
#include <Core/Game.hpp>
#include <math.h>

/**
 * Load font from given path
 * \param f_path the path on the filesystem to load a font from.
*/
TTF_Font* FontManager::load_font(const char* f_path, int size){
    TTF_Font* font = NULL;
    font = TTF_OpenFont(f_path, size);
    if (font == NULL){
        std::cout << "Failed to load font " << f_path << "!SDL_ttf Error: " << TTF_GetError() << '\n';
    }
    return font;
}

TTF_Text* FontManager::load_text(const std::string text, int width, int size, TTF_Font* font, SDL_Color color){
    if (!font) font = Game::font;
    TTF_SetFontSize(font, size);

    SDL_Surface* surface = NULL;
    surface = TTF_RenderText_Solid_Wrapped(font, text.c_str(), color, width);
    if (surface == NULL){
        std::cout << "Failed to load text! SDL_ttf Error: " << TTF_GetError() << '\n';
    }
    SDL_Texture* texture = TextureManager::load_texture(surface);
    TTF_Text *res = new TTF_Text(text, texture, surface->w, surface->h);
    SDL_FreeSurface(surface);
    return res;
}

void FontManager::draw_text(TTF_Text* text, SDL_Rect* dst){
    TextureManager::draw(text->texture, &text->src, dst);
}

void FontManager::draw_text(const std::string mText, SDL_Rect* dst, int size, TTF_Font* font, SDL_Color color){
    if (!font) font = Game::font;

    TTF_Text* text = load_text(mText, dst->w, size, font, color);
    draw_text(text, dst);
}
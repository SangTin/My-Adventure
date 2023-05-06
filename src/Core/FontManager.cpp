#include <iostream>
#include <Core/FontManager.hpp>
#include <Core/TextureManager.hpp>
#include <Core/Game.hpp>

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

TTF_Text FontManager::load_text(TTF_Font* font, const char* text, SDL_Color color){
    SDL_Surface* surface = NULL;
    surface = TTF_RenderText_Solid(font, text, color);
    if (surface == NULL){
        std::cout << "Failed to load text! SDL_ttf Error: " << TTF_GetError() << '\n';
    }
    SDL_Texture* texture = TextureManager::load_texture(surface);
    TTF_Text res(texture, surface->w, surface->h);
    SDL_FreeSurface(surface);
    return res;
}

void FontManager::draw_text(TTF_Text* text, SDL_Rect* dst){
    TextureManager::draw(text->texture, &text->src, dst);
}

void FontManager::draw_text(TTF_Font* font, const char* mText, SDL_Rect* dst, SDL_Color color){
    TTF_Text text = load_text(font, mText, color);
    draw_text(&text, dst);
}

void FontManager::draw_text(const char* mText, SDL_Rect* dst, SDL_Color color){
    TTF_Text text = load_text(Game::font, mText, color);
    draw_text(&text, dst);
}
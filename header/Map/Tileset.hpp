#pragma once
#include <Tileson/tileson.hpp>
#include <SDL2/SDL.h>

class Tileset{
    private:
        SDL_Texture* texture;
        int firstGID;
        int tileCount;
        tson::Vector2i tileSize;
};
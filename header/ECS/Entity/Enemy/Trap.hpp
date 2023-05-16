#pragma once
#include <ECS/Entity/Tile.hpp>

class Trap : public Tile{
    public:
        Trap(SDL_Texture* texture, int x, int y, SDL_Rect src, int tileID, double scale = 2);
        void init() override;
        void update() override;
};
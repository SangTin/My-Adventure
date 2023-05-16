#pragma once
#include <ECS/Component/Components.hpp>
#include <SDL2/SDL.h>

class Tile : public Entity{
    protected:
        TransformComponent* transform;
        SpriteComponent* sprite;
        ColliderComponent* collider;
    public:
        Tile() = default;
        Tile(SDL_Texture* texture, int x, int y, SDL_Rect src, int tileID, double scale = 2);
        void add_map_collider();
};
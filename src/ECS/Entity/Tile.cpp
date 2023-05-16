#include <ECS/Entity/Tile.hpp>
#include <iostream>
#include <UI/Camera.hpp>

Tile::Tile(SDL_Texture* texture, int x, int y, SDL_Rect src, int tileID, double scale){
    transform = &add_component<TransformComponent>(x, y, src.w, src.h, scale);
    sprite = &add_component<SpriteComponent>(texture, src, true);
}

void Tile::add_map_collider(){
    collider = &add_component<ColliderComponent>("MapTile");
    add_group(Base::groupMap);
}
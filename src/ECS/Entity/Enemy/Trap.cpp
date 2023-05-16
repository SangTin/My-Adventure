#include <ECS/Entity/Enemy/Trap.hpp>
#include <Core/Collision.hpp>
#include <State/Play.hpp>

Trap::Trap(SDL_Texture* texture, int x, int y, SDL_Rect src, int tileID, double scale){
    transform = &add_component<TransformComponent>(x, y, src.w, src.h, scale);
    sprite = &add_component<SpriteComponent>(texture, src, true);
}

void Trap::init(){
    collider = &add_component<ColliderComponent>("Trap");
    add_group(Base::groupMap);
}

void Trap::update(){
    if (Collision::AABB(Play::player->get_hitbox(), transform->hitbox)){
        Play::player->take_damage();
    }
}
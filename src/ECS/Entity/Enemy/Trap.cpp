#include <ECS/Entity/Enemy/Trap.hpp>
#include <Core/Collision.hpp>
#include <State/Play.hpp>

void Trap::init(){
    collider = &add_component<ColliderComponent>("Trap");
    add_group(Base::groupMap);
}

void Trap::update(){
    if (Collision::AABB(Play::player->get_hitbox(), transform->hitbox)){
        Play::player->take_damage();
    }
}
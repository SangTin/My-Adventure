#include <Core/Collision.hpp>
#include <ECS/ECS.hpp>
#include <ECS/Component/ColliderComponent.hpp>
#include <Map/GameMap.hpp>

bool Collision::AABB(const SDL_Rect a, const SDL_Rect b){
    if (a.x + a.w >= b.x && b.x + b.w >= a.x 
    && a.y + a.h >= b.y && b.y + b.h >= a.y)
    {
        return true;
    }
    return false;
}

bool Collision::AABB(const ColliderComponent* a, const ColliderComponent* b){
    if (!a || !b) return false;
    return AABB(a->collider, b->collider);
}

bool Collision::map_collision(const SDL_Rect a){
    bool res = false;
    for (auto& e : GameMap::manager->get_group(Base::groupMap)){
        ColliderComponent* tileCollider = &e->get_component<ColliderComponent>();
        if (AABB(tileCollider->collider, a)) res = true;
    }
    return res;
}
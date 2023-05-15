#pragma once
#include <SDL2/SDL.h>
#include <string>

class ColliderComponent;

class Collision{
    public:
        static bool AABB(const SDL_Rect a, const SDL_Rect b);
        static bool AABB(const ColliderComponent* a, const ColliderComponent* b);
        static bool map_collision(const SDL_Rect a);
};
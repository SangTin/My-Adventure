#pragma once
#include <ECS/ECS.hpp>
#include <string>
#include "TransformComponent.hpp"

class ColliderComponent : public Component{
    private:
        std::string tag;
        TransformComponent* transform;
    public:
        SDL_Rect collider;

        ColliderComponent(const std::string);
        void init() override;
        void update() override;
};
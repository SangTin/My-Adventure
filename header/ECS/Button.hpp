#pragma once
#include "ECS.hpp"
#include "SpriteComponent.hpp"

class Button : public Component{
    protected:
        TransformComponent* transform;
        SpriteComponent* sprite;

        bool selected, released;
        bool pressed;
        bool focus;
        
    public:
        Button() = default;
        void init() override;
        void update() override;
};
#pragma once
#include "ECS.hpp"
#include "TransformComponent.hpp"
#include "SpriteComponent.hpp"

class KeyboardController : public Component{
    private:
        TransformComponent* transform;
        SpriteComponent* sprite;
};
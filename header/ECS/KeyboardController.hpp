#pragma once
#include "ECS.hpp"
#include "SpriteComponent.hpp"
#include <map>

class KeyboardController : public Component{
    private:
        TransformComponent* transform;
        SpriteComponent* sprite;
        std::map<SDL_KeyCode, int> keys;
    public:
        void init() override;
        void update() override;
};
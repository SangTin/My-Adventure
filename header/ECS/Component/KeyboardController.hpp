#pragma once
#include <ECS/ECS.hpp>
#include <Core/Vector2D.hpp>
#include <map>

class KeyboardController : public Component{
    private:
        std::map<SDL_KeyCode, int> keys;
    public:
        void update() override;
        Vector2D get_direction();
};
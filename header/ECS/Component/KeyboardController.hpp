#pragma once
#include <ECS/ECS.hpp>
#include <map>

class KeyboardController : public Component{
    private:
        std::map<SDL_KeyCode, int> keys;
    public:
        void update() override;
};
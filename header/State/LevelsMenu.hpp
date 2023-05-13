#pragma once
#include "GameState.hpp"
#include <SDL2/SDL.h>
#include <vector>

class LevelsMenu : public GameState{
    private:
        Entity *background;
        TransformComponent* transform;
        std::vector<ClickedButton*> levels;
    public:
        void init() override;
        void update() override;
};
#pragma once
#include "GameState.hpp"

class GameOver : public GameState{
    private:
        Entity *background;
        TransformComponent* transform;
        Mix_Music* soundtrack;
        
        ClickedButton *Continue;
    public:
        void init() override;
        void update() override;

    private:
        void play();
};
#pragma once
#include "GameState.hpp"

class PauseMenu : public GameState{
    private:
        Entity *background;
        TransformComponent* transform;
        ClickedButton *Continue, *Home, *Option, *Quit;
    public:
        void init() override;
        void update() override;

    private:
        void play();
        void home();
        void quit();
        void option();
};
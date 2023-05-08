#pragma once
#include "GameState.hpp"
#include <SDL2/SDL_mixer.h>

class Menu : public GameState{
    private:
        ClickedButton *Play, *Option, *Quit;
        std::vector<ClickedButton*> buttons;

    public:
        void init() override;
        void update() override;

    private:
        void play();
};
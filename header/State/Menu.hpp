#pragma once
#include "GameState.hpp"
#include <SDL2/SDL_mixer.h>

class Menu : public GameState{
    private:
        Mix_Music* soundtrack;
        ClickedButton *Play, *Option, *Quit;

        Player* testPlayer;
    public:
        void init() override;
        void update() override;
        void destroy() override;

    private:
        void play();
        void quit();
        void option();
};
#pragma once
#include "GameState.hpp"
#include <SDL2/SDL_mixer.h>

class Menu : public GameState{
    private:
        Entity *background;
        TransformComponent* transform;

        Mix_Music* soundtrack;
        ClickedButton *Play, *Option, *Quit;
    public:
        void init() override;
        void update() override;
        void render() override;
        void destroy() override;

    private:
        void play();
        void quit();
        void option();
};
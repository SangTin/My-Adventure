#pragma once
#include "GameState.hpp"
#include <Map/GameMap.hpp>
#include <Tileson/tileson.hpp>
#include <SDL2/SDL_mixer.h>

class Play : public GameState{
    private:
        ClickedButton *Pause;
        GameMap map;
        Mix_Music* soundtrack;

        TransformComponent* healthTranform;
    public:
        static Player *player;

        Play(int level);
        ~Play();
        void init() override;
        void update() override;
        void render() override;

    private:
        void pause();
};
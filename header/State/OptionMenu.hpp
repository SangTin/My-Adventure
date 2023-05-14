#pragma once
#include "GameState.hpp"

class OptionMenu : public GameState{
    private:
        Entity *background;
        TransformComponent* transform;
        Slider *musicVolume, *sfxVolume;
        ClickedButton *music, *sfx;
        Mix_Chunk *sfxSound;

    public:
        void init() override;
        void update() override;
};
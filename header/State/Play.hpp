#pragma once
#include "GameState.hpp"

class Play : public GameState{
    private:
        ClickedButton *Pause;

    public:
        Play(int level);
        void init() override;
        void update() override;

    private:
        void pause();
};
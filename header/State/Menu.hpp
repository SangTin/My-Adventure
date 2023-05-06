#pragma once
#include "GameState.hpp"

class Menu : public GameState{
    private:
        Entity *Play, *Option, *Quit;

        Entity* create_button(const char* path, int x, int y, int width, int height, double scale);
    public:
        void init() override;
        
};
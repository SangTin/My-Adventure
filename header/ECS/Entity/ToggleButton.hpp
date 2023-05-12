#pragma once
#include "Button.hpp"
#include <string>

class ToggleButton : public Button{
    private:
        SpriteComponent* sprite;
        Sound* sound = nullptr;
        bool curStats = 0;
    public:
        ToggleButton(const char* path, SDL_Rect dst, double scale);
        ToggleButton(const char* path, int x, int y, int width, int height, double scale);
        void init_sprite(const char* path, int width, int height);
        void update() override;
        void  change_stats(bool stats);
};
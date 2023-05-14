#pragma once
#include "Button.hpp"
#include <string>

class ClickedButton : public Button{
    private:
        SpriteComponent* sprite;
        Sound* sound = nullptr;
        int framesY, curFrameY = 0;
    public:
        ClickedButton(const char* path, SDL_Rect dst, double scale);
        ClickedButton(const char* path, int x, int y, int width, int height, double scale);
        void init_sprite(const char* path, int width, int height);
        void add_sound(const std::string name, const char* path) override;
        void update() override;
        void change_frameY(int y);
};
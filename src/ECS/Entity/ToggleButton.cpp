#include <ECS/Entity/ToggleButton.hpp>
#include <UI/Mouse.hpp>

ToggleButton::ToggleButton(const char* path, SDL_Rect dst, double scale){
    init_transform(dst.x, dst.y, dst.w, dst.h, scale);
    init_sprite(path, dst.w, dst.h);
}

ToggleButton::ToggleButton(const char* path, int x, int y, int width, int height, double scale){
    init_transform(x, y, width, height, scale);
    init_sprite(path, width, height);
}

void ToggleButton::init_sprite(const char* path, int width, int height){
    sprite = &add_component<SpriteComponent>(path, width, height);
}

void ToggleButton::update(){
    Button::update();
    pressed = false;
    if (SDL_PointInRect( Mouse::get_position(), &transform->dst )){
        if (Mouse::get_button_state(SDL_BUTTON_LEFT) && released){
            released = false;
        }
        else{
            if (!Mouse::get_button_state(SDL_BUTTON_LEFT)){
                if (!released){
                    pressed = true;
                    change_stats(curStats ^ 1);
                }
                released = true;
            }
        }
    }
    else{
        released = true;
    }
}

void ToggleButton::change_stats(bool stats){
    curStats = stats;
    sprite->src.x = (sprite->src.w * curStats);
}
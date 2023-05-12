#include <ECS/Entity/ClickedButton.hpp>
#include <UI/Mouse.hpp>

ClickedButton::ClickedButton(const char* path, SDL_Rect dst, double scale){
    init_transform(dst.x, dst.y, dst.w, dst.h, scale);
    init_sprite(path, dst.w, dst.h);
}

ClickedButton::ClickedButton(const char* path, int x, int y, int width, int height, double scale){
    init_transform(x, y, width, height, scale);
    init_sprite(path, width, height);
}

void ClickedButton::init_sprite(const char* path, int width, int height){
    sprite = &add_component<SpriteComponent>(path, width, height);
}

void ClickedButton::add_sound(const std::string name, const char* path){
    //Sound is not initialized
    if (!sound){
        sound = &add_component<Sound>();
    }
    sound->add_sound(name, path);
}

#define DEFAULT 0
#define SELECTED 1
#define PRESSED 2

void ClickedButton::update(){
    Button::update();
    pressed = false;
    if (SDL_PointInRect( Mouse::get_position(), &transform->dst )){
        if (!selected){
            selected = true;
            if (sound){
                sound->play_sound("Hover");
            }
        }
        if (Mouse::get_button_state(SDL_BUTTON_LEFT) && released){
            released = false;
            sprite->src.x = (sprite->src.w * PRESSED);
        }
        else{
            if (!Mouse::get_button_state(SDL_BUTTON_LEFT)){
                if (!released){
                    pressed = true;
                    if (sound){
                        sound->play_sound("Pressed");
                    }
                }
                released = true;
                sprite->src.x = (sprite->src.w * SELECTED);
            }
        }
    }
    else{
        if (selected){
            selected = false;
            released = true;
        }
        sprite->src.x = (sprite->src.w * DEFAULT);
    }
}
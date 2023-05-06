#include <ECS/ClickedButton.hpp>
#include <UI/Mouse.hpp>

void ClickedButton::update(){
    Button::update();
    sprite->update();
    pressed = false;
    if (focus && SDL_PointInRect(Mouse::get_position(), &transform->dst)){
        if (!selected){
            selected = true;
        }
        if (Mouse::get_button_state(Base::leftMouse) && released){
            released = false;

            //Pressed_sprite
            sprite->src.x = sprite->src.w * 2;
            sprite->src.y = 0;
        }
        else{
            if (!Mouse::get_button_state(Base::leftMouse)){
                if (!released){
                    pressed = true;
                }
                released = true;

                //Selected_sprite
                sprite->src.x = sprite->src.w;
                sprite->src.y = 0;
            }
        }
    }
    else{
        if (selected){
            selected = false;
            released = true;
        }

        //Normal_sprite
        sprite->src.x = 0;
        sprite->src.y = 0;
    }
}
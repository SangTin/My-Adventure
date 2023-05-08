#include <ECS/Button/Button.hpp>
#include <UI/Mouse.hpp>

void Button::init(){
    transform = &entity->get_component<TransformComponent>();
    sprite = &entity->get_component<SpriteComponent>();
    sound = &entity->get_component<Sound>();
    selected = false;
    released = true;
    focus = true;
    pressed = false;
}

void Button::update(){
    if (SDL_PointInRect(Mouse::get_position(), &transform->dst)){
        Mouse::change_mouse_state(Base::mousePointing);
    }
}

void Button::lose_focus(){
    if (!focus) return;
    focus = false;
    update();
}

void Button::gain_focus(){
    if (focus) return;
    focus = true;
    update();
}

void Button::add_sound(const std::string name, const char* path){
    sound->add_sound(name, path);
}

void Button::add_sound(const std::string name, Mix_Chunk* sfx){
    sound->add_sound(name, sfx);
}

bool Button::is_pressed(){
    return pressed;
}
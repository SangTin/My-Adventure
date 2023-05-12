#include <ECS/Entity/Button.hpp>
#include <UI/Mouse.hpp>

Button::Button(SDL_Rect dst, double scale){
    init_transform(dst.x, dst.y, dst.w, dst.h, scale);
}

Button::Button(int x, int y, int width, int height, double scale){
    init_transform(x, y, width, height, scale);
}

void Button::init_transform(int x, int y, int width, int height, double scale){
    transform = &add_component<TransformComponent>(x, y, width, height, scale);
}

void Button::init(){
    add_group(Base::groupButtons);
}

void Button::update(){
    Entity::update();
    if (SDL_PointInRect(Mouse::get_position(), &transform->dst ) ){
        Mouse::change_mouse_state(Base::mousePointing);
        if (Mouse::get_button_state(SDL_BUTTON_LEFT)){
            Mouse::change_mouse_state(Base::mousePointingHolding);
        }
    }
}

void Button::centered(){
    transform->centered();
}

bool Button::is_pressed(){
    return pressed;
}

SDL_Rect Button::get_dst(){
    return transform->dst;
}
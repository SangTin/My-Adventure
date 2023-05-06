#include <ECS/Button.hpp>
#include <UI/Mouse.hpp>

void Button::init(){
    transform = &entity->get_component<TransformComponent>();
    sprite = &entity->get_component<SpriteComponent>();
}

void Button::update(){
    if (SDL_PointInRect(Mouse::get_position(), &transform->dst)){
        Mouse::change_mouse_state(Base::mousePointing);
    }
}
#include <ECS/Entity/Character.hpp>

Character::Character(int x, int y, int width, int height, double scale){
    transform = &add_component<TransformComponent>(x, y, width, height, scale);
    animation = &add_component<AnimationComponent>(width, height);
}

void Character::add_action(const std::string name, const char* path, int frames, int speed){
    animation->add_animation(name, path, frames, speed);
}

void Character::play_action(const std::string name){
    animation->play(name);
}
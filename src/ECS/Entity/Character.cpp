#include <ECS/Entity/Character.hpp>

Character::Character(int x, int y, int width, int height, double scale){
    transform = &add_component<TransformComponent>(x, y, width, height, scale);
    animation = &add_component<AnimationComponent>(width, height);
}

void Character::add_action(const std::string name, const char* path){
    animation->add_animation(name, path);
}

void Character::play_action(const std::string name, int fSpeed, int flip){
    animation->play(name, fSpeed, flip);
    action = true;
}
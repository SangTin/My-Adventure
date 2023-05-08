#include <ECS/Physic/Gravity.hpp>

void Gravity::init(){
    transform = &entity->get_component<TransformComponent>();
}

void Gravity::update(){
    gravitySpeed += 0.05;
    if (gravitySpeed > 3) gravitySpeed = 3;
    transform->add_velocity(0, gravitySpeed);
}
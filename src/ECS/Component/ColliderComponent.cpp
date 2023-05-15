#include <ECS/Component/ColliderComponent.hpp>

ColliderComponent::ColliderComponent(const std::string tag){
    this->tag = tag;
}

void ColliderComponent::init(){
    transform = &entity->get_component<TransformComponent>();
}

void ColliderComponent::update(){
    collider = transform->dst;
}
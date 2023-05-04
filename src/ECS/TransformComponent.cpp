#include <ECS/TransformComponent.hpp>

TransformComponent::TransformComponent(double x, double y){
    position = Vector2D(x, y);
}

void TransformComponent::update(){
    position += velocity * speed;
}

void TransformComponent::change_position(Vector2D mPosition){
    position = mPosition;
}

void TransformComponent::change_position(double x, double y){
    change_position(Vector2D(x, y));
}

Vector2D TransformComponent::get_position(){
    return position;
}

double TransformComponent::get_x(){
    return position.x;
}

double TransformComponent::get_y(){
    return position.y;
}
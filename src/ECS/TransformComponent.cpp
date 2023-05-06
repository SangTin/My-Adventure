#include <ECS/TransformComponent.hpp>

TransformComponent::TransformComponent(int x, int y, int width, int height, double scale){
    dst = {x, y, width, height};
    position = Vector2D(x, y);
    this->scale = scale;
}

void TransformComponent::update(){
    position += velocity * speed;
    dst.x = position.x;
    dst.y = position.y;
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
#include <ECS/Component/TransformComponent.hpp>
#include <Core/Game.hpp>

TransformComponent::TransformComponent(int x, int y, int width, int height, double scale){
    dst = {x, y, int(width * scale), int(height * scale)};
    position = Vector2D(x, y);
    this->scale = scale;
}

void TransformComponent::change_position(Vector2D mPosition){
    position = mPosition;
    dst.x = position.x;
    dst.y = position.y;
}

void TransformComponent::change_position(double x, double y){
    change_position(Vector2D(x, y));
}

void TransformComponent::centered(){
    double x = position.x + Game::center.x - dst.w / 2;
    double y = position.y + Game::center.y - dst.h / 2;
    change_position(x, y);
}

Vector2D TransformComponent::get_position(){
    return position;
}

void TransformComponent::move(Vector2D s){
    position += s;
}

void TransformComponent::move(double x, double y){
    move(Vector2D(x, y));
}
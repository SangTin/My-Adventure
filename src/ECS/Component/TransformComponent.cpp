#include <ECS/Component/TransformComponent.hpp>
#include <Core/Game.hpp>

#define HITBOX_TOP hitboxInfo.x
#define HITBOX_BOTTOM hitboxInfo.y
#define HITBOX_LEFT hitboxInfo.w
#define HITBOX_RIGHT hitboxInfo.h

TransformComponent::TransformComponent(int x, int y, int width, int height, double scale){
    hitbox = dst = {x, y, int(width * scale), int(height * scale)};
    hitboxInfo = {0, 0, 0, 0};
    position = Vector2D(x, y);
    this->scale = scale;
}

void TransformComponent::update(){
    dst.x = position.x;
    dst.y = position.y;
    hitbox.x = HITBOX_LEFT * scale + dst.x;
    hitbox.y = HITBOX_TOP * scale + dst.y;
    hitbox.w = dst.w - (HITBOX_LEFT + HITBOX_RIGHT) * scale;
    hitbox.h = dst.h - (HITBOX_TOP + HITBOX_BOTTOM) * scale;
}

void TransformComponent::change_position(Vector2D mPosition){
    position = mPosition;
    update();
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
    update();
}

void TransformComponent::move(double x, double y){
    move(Vector2D(x, y));
}

void TransformComponent::moveX(double x){
    move(Vector2D(x, 0));
}

void TransformComponent::moveY(double y){
    move(Vector2D(0, y));
}

void TransformComponent::add_hitbox(int top, int bottom, int left, int right){
    hitboxInfo = {top, bottom, left, right};
}
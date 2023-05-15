#include <ECS/Entity/Enemy/Enemy.hpp>
#include <Core/GameTimer.hpp>
#include <Core/Collision.hpp>
#include <Map/GameMap.hpp>

void Enemy::init(){
    rigidbody = &add_component<RigidBody>();
    add_group(Base::groupEnemies);
}

void Enemy::update(){
    delta_time = GameTimer::get_DT();

    rigidbody->stop_force();
    rigidbody->update(delta_time);
}
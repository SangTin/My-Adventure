#include <ECS/Component/RigidBody.hpp>
#include <Core/GameTimer.hpp>
#include <Core/Collision.hpp>
#include <Map/GameMap.hpp>

RigidBody::RigidBody(){
    m_Mass = UNI_MASS;
    m_Gravity = GRAVITY;
}

void RigidBody::init(){
    transform = &entity->get_component<TransformComponent>();
}

void RigidBody::update(double dt){
    m_Accelaration.x = (m_Force.x + m_Friction.x) / m_Mass;
    m_Accelaration.y = m_Gravity + m_Force.y / m_Mass;
    m_Velocity = m_Accelaration * dt;
    m_Position = m_Velocity * dt;

    mapCollisionDirect = Vector2D(0, 0);

    //Move on Y axis
    m_lastPosition = transform->get_position();
    transform->moveY(m_Position.y);
    if (Collision::map_collision( transform->hitbox )){
        if (m_Position.y > 0){
            mapCollisionDirect.y = 1;
        }
        else{
            mapCollisionDirect.y = -1;
        }
        transform->change_position(m_lastPosition);
    }

    //Move on X axis
    m_lastPosition = transform->get_position();
    transform->moveX(m_Position.x);
    if (Collision::map_collision( transform->hitbox )){
        if (m_Position.x > 0){
            mapCollisionDirect.x = 1;
        }
        else{
            mapCollisionDirect.x = -1;
        }
        transform->change_position(m_lastPosition);
    }
    if (transform->hitbox.x < 0 || 
        (transform->hitbox.x + transform->hitbox.w > GameMap::get_map_width()))
    {
        transform->change_position(m_lastPosition);
    } 
}

void RigidBody::set_mass(double mass){
    m_Mass = mass;
}

void RigidBody::set_gravity(double gravity){
    m_Gravity = gravity;
}

void RigidBody::apply_force(Vector2D F){
    m_Force = F;
}

void RigidBody::apply_forceX(double Fx){
    m_Force.x = Fx;
}

void RigidBody::apply_forceY(double Fy){
    m_Force.y = Fy;
}

void RigidBody::stop_force(){
    m_Force = Vector2D(0, 0);
}
        
void RigidBody::apply_friction(Vector2D Fr){
    m_Friction = Fr;
}
        
void RigidBody::stop_friction(){
    m_Friction = Vector2D(0, 0);
}
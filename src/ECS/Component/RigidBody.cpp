#include <ECS/Component/RigidBody.hpp>
#include <Core/GameTimer.hpp>

#define UNI_MASS 1.0
#define GRAVITY 9.8

RigidBody::RigidBody(){
    m_Mass = UNI_MASS;
    m_Gravity = GRAVITY;
}

void RigidBody::update(double dt){
    m_Accelaration.x = (m_Force.x + m_Friction.x) / m_Mass;
    m_Accelaration.y = m_Gravity + m_Force.y / m_Mass;
    m_Velocity = m_Accelaration * dt;
    m_Position = m_Velocity * dt;
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


double RigidBody::get_mass(){
    return m_Mass;
}

Vector2D RigidBody::get_position(){
    return m_Position;
}

Vector2D RigidBody::get_velocity(){
    return m_Velocity;
}

Vector2D RigidBody::get_accelaration(){
    return m_Accelaration;
}
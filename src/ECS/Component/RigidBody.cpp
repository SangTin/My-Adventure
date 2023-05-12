#include <ECS/Component/RigidBody.hpp>
#include <Core/GameTimer.hpp>

#define UNI_MASS 1.0
#define GRAVITY 9.8

RigidBody::RigidBody(){
    m_Mass = UNI_MASS;
    m_Gravity = GRAVITY;
}

void RigidBody::update(){
    m_Accelaration.x = (m_Force.x + m_Friction.x) / m_Mass;
    m_Accelaration.y = m_Gravity + m_Force.y / m_Mass;
    m_Velocity = m_Accelaration * GameTimer::get_DT();
    m_Position = m_Velocity * GameTimer::get_DT();
}

inline void RigidBody::set_mass(double mass){
    m_Mass = mass;
}

inline void RigidBody::set_gravity(double gravity){
    m_Gravity = gravity;
}

inline void RigidBody::apply_force(Vector2D F){
    m_Force = F;
}

inline void RigidBody::apply_forceX(double Fx){
    m_Force.x = Fx;
}

inline void RigidBody::apply_forceY(double Fy){
    m_Force.y = Fy;
}

inline void RigidBody::stop_force(){
    m_Force = Vector2D(0, 0);
}
        
inline void RigidBody::apply_friction(Vector2D Fr){
    m_Friction = Fr;
}
        
inline void RigidBody::stop_friction(){
    m_Friction = Vector2D(0, 0);
}
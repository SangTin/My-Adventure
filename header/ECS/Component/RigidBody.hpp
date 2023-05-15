#pragma once
#include <ECS/ECS.hpp>
#include "TransformComponent.hpp"
#include <Core/Vector2D.hpp>

#define UNI_MASS 1.0
#define GRAVITY 3.0

class RigidBody : public Component{
    private:
        TransformComponent* transform;

        double m_Mass, m_Gravity;
        Vector2D m_Force;
        Vector2D m_Friction;

        Vector2D m_Velocity;
        Vector2D m_Accelaration;
        
        Vector2D m_Position;
        Vector2D m_lastPosition;

        Vector2D mapCollisionDirect;
    public:
        RigidBody();
        void update(double dt);
        void init();
        
        void set_mass(double mass);
        void set_gravity(double gravity);

        void apply_force(Vector2D F);
        void apply_forceX(double Fx);
        void apply_forceY(double Fy);
        void stop_force();
        
        void apply_friction(Vector2D F);
        void stop_friction();

        //Getter
        inline double get_gravity(){ return m_Gravity; }
        inline Vector2D get_force() { return m_Force; }
        inline double get_mass(){ return m_Mass; }
        inline Vector2D get_position(){ return m_Position; }
        inline Vector2D get_velocity(){ return m_Velocity; }
        inline Vector2D get_accelaration(){ return m_Accelaration; }
        inline bool is_grounded(){ return (mapCollisionDirect.y == 1); }
        inline Vector2D get_map_collision() { return mapCollisionDirect;}
        inline double cal_jumpForce(){ return m_Gravity + GRAVITY; }
};
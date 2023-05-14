#pragma once
#include <ECS/ECS.hpp>
#include <Core/Vector2D.hpp>

class RigidBody : public Component{
    private:
        double m_Mass, m_Gravity;
        Vector2D m_Force;
        Vector2D m_Friction;

        Vector2D m_Velocity;
        Vector2D m_Accelaration;
        
        Vector2D m_Position;
    public:
        RigidBody();
        void update(double dt);
        
        void set_mass(double mass);
        void set_gravity(double gravity);

        void apply_force(Vector2D F);
        void apply_forceX(double Fx);
        void apply_forceY(double Fy);
        void stop_force();
        
        void apply_friction(Vector2D F);
        void stop_friction();

        double get_mass();
        Vector2D get_position();
        Vector2D get_velocity();
        Vector2D get_accelaration();
};
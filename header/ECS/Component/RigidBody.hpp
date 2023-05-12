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
        void update() override;
        
        inline void set_mass(double mass);
        inline void set_gravity(double gravity);

        inline void apply_force(Vector2D F);
        inline void apply_forceX(double Fx);
        inline void apply_forceY(double Fy);
        inline void stop_force();
        
        inline void apply_friction(Vector2D F);
        inline void stop_friction();
};
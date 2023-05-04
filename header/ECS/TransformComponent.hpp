#pragma once
#include "ECS.hpp"
#include <Core/Vector2D.hpp>

class TransformComponent : public Component{
    private:
        Vector2D position, velocity;
        double speed = 2;
    public:
        TransformComponent(double x = 0, double y = 0);
        void update() override;

        void change_position(Vector2D mPosition);
        void change_position(double x, double y);
        Vector2D get_position();
        double get_x();
        double get_y();
};
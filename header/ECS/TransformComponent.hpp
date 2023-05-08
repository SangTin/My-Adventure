#pragma once
#include "ECS.hpp"
#include <SDL2/SDL.h>
#include <Core/Vector2D.hpp>

class TransformComponent : public Component{
    private:
        Vector2D position, velocity;
        double speed = 2;
    public:
        SDL_Rect dst;
        double scale;
        
    public:
        TransformComponent(int x = 0, int y = 0, int width = 0, int height = 0, double scale = 1);
        void update() override;

        void change_position(Vector2D mPosition);
        void change_position(double x, double y);
        void centered();
        Vector2D get_position();
        double get_x();
        double get_y();

        void change_velocity(Vector2D mVelocity);
        void change_velocity(double x, double y);
        void add_velocity(Vector2D mVelocity);
        void add_velocity(double x, double y);
};
#pragma once
#include <ECS/ECS.hpp>
#include <SDL2/SDL.h>
#include <Core/Vector2D.hpp>

class TransformComponent : public Component{
    private:
        Vector2D position;
    public:
        SDL_Rect dst;
        double scale;
        
    public:
        TransformComponent(int x = 0, int y = 0, int width = 0, int height = 0, double scale = 1);

        void change_position(Vector2D mPosition);
        void change_position(double x, double y);
        void centered();
        Vector2D get_position();

        void move(Vector2D s);
        void move(double x, double y);
};
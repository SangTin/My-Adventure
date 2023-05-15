#pragma once
#include <ECS/ECS.hpp>
#include <SDL2/SDL.h>
#include <Core/Vector2D.hpp>

class TransformComponent : public Component{
    private:
        Vector2D position;
        SDL_Rect hitboxInfo;
        
    public:
        SDL_Rect dst, hitbox;
        double scale;
        
    public:
        TransformComponent(int x = 0, int y = 0, int width = 0, int height = 0, double scale = 1);
        void update() override;
        
        void change_position(Vector2D mPosition);
        void change_position(double x, double y);
        void centered();
        Vector2D get_position();

        void move(Vector2D s);
        void move(double x, double y);
        void moveX(double x);
        void moveY(double Y);

        void add_hitbox(int top, int bottom, int left, int right);
};
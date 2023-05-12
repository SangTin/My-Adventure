#pragma once
#include <ECS/Component/Components.hpp>

class Button : public Entity{
    protected:
        TransformComponent* transform;

        bool selected = false;
        bool pressed = false, released = true;
    public:
        Button() = default;
        Button(SDL_Rect dst, double scale);
        Button(int x, int y, int width, int height, double scale);
        void init_transform(int x, int y, int width, int height, double scale);

        void init() override;
        void update() override;
        
        void centered();
        bool is_pressed();

        SDL_Rect get_dst();
};
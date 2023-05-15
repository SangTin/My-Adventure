#pragma once
#include <Core/Vector2D.hpp>
#include <SDL2/SDL.h>

class Camera{
    private:
        static Vector2D m_Position, *m_Target;
        static SDL_Rect m_Viewbox, m_UpdateArea;
    public:
        static void update();
        static void set_target(Vector2D *target);
        static SDL_Rect get_viewbox();
        static Vector2D get_position();
};
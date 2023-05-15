#pragma once
#include <SDL2/SDL.h>
#include <Core/Game.hpp>

class HandleEvent{
    private:
        static const Uint8* m_KeyStates;
        static bool focus;
        static bool newEvent;
    public:
        static SDL_Event event;

        static void listen();
        static bool get_key_down(const SDL_Scancode key);
        static bool is_key_pressed(const SDL_Keycode key);
        static inline bool lose_focus() { return !focus; }
        static inline bool gain_focus() { return !focus; }
    private:
        static void key_down();
        static void key_up();
};
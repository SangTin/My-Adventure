#pragma once
#include <bitset>
#include <SDL2/SDL.h>
#include <core/Base.hpp>

constexpr std::size_t maxMouseState = 5;

class Mouse{
    private:
        static Base::mouseStats mouseState;
        static Uint32 mouseMask;
        static SDL_Point position;
        static SDL_Cursor *normal, *pointing, *holding;
    public:
        static void init();
        static void update(); 
        static void change_mouse_state(Base::mouseStats mStat);
        static bool get_button_state(int mButton);
        static SDL_Point get_position();
};
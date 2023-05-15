#include <Core/GameTimer.hpp>
#include <SDL2/SDL.h>

const int TARGET_FPS = 144;
const double TARGET_DELTATIME = 1.5;

double GameTimer::m_DeltaTime;
double GameTimer::m_OldTime;

void GameTimer::update_timer(){
    m_DeltaTime = (SDL_GetTicks() - m_OldTime) * (TARGET_FPS / 1000.0);
    if (m_DeltaTime > TARGET_DELTATIME){
        m_DeltaTime = TARGET_DELTATIME;
    }
    m_OldTime = SDL_GetTicks();
}
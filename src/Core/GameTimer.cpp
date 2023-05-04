#include <Core/GameTimer.hpp>
#include <SDL2/SDL.h>

unsigned int GameTimer::m_OldTick;
unsigned int GameTimer::m_CurrentTick;

void GameTimer::update_timer(){
    m_OldTick = m_CurrentTick;
    m_CurrentTick = SDL_GetTicks();
}

double GameTimer::get_DT(){
    double res = (m_CurrentTick - m_OldTick) / 1000.0;
    if (res > 0.2) res = 0.2;
    return res;
}
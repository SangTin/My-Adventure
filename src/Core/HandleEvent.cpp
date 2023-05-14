#include <Core/HandleEvent.hpp>


bool HandleEvent::focus = true;
SDL_Event HandleEvent::event;
const Uint8* HandleEvent::m_KeyStates = SDL_GetKeyboardState(nullptr);

void HandleEvent::listen(){
    if (SDL_PollEvent( &event )){
        switch (event.type)
        {
        case SDL_QUIT:
            Game::quit();
            break;

        case SDL_WINDOWEVENT:
            if (event.window.event == SDL_WINDOWEVENT_FOCUS_GAINED){
                focus = true;
            }
            if (event.window.event == SDL_WINDOWEVENT_FOCUS_LOST){
                focus = false;
            }
            break;
        case SDL_KEYDOWN: key_down(); break;
        case SDL_KEYUP: key_up(); break;
        }

    }
}

bool HandleEvent::get_key_down(const SDL_Scancode key){
    return (m_KeyStates[key] == 1);
}

void HandleEvent::key_down(){
    m_KeyStates = SDL_GetKeyboardState(nullptr);
}

void HandleEvent::key_up(){
    m_KeyStates = SDL_GetKeyboardState(nullptr);
}
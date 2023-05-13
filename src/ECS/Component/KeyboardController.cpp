#include <ECS/Component/KeyboardController.hpp>
#include <Core/Game.hpp>

void KeyboardController::update(){
    if (Game::event.type == SDL_KEYDOWN){
        switch (Game::event.key.keysym.sym)
        {
        case SDLK_UP:
        case SDLK_w:
            keys[SDLK_w] = keys[SDLK_s] + 1;
            break;
        case SDLK_DOWN:
        case SDLK_s:
            keys[SDLK_s] = keys[SDLK_w] + 1;
            break;
        case SDLK_LEFT:
        case SDLK_a:
            keys[SDLK_a] = keys[SDLK_d] + 1;
            break;
        case SDLK_RIGHT:
        case SDLK_d:
            keys[SDLK_d] = keys[SDLK_a] + 1;
            break;
        }
    }
    if (Game::event.type == SDL_KEYUP){
        switch (Game::event.key.keysym.sym)
        {
        case SDLK_UP:
        case SDLK_w:
            keys[SDLK_w] = 0;
            break;
        case SDLK_DOWN:
        case SDLK_s:
            keys[SDLK_s] = 0;
            break;
        case SDLK_LEFT:
        case SDLK_a:
            keys[SDLK_a] = 0;
            break;
        case SDLK_RIGHT:
        case SDLK_d:
            keys[SDLK_d] = 0;
            break;
        }
    }
}
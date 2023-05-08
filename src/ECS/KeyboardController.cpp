#include <ECS/KeyboardController.hpp>
#include <Core/Game.hpp>

void KeyboardController::init(){
    transform = &entity->get_component<TransformComponent>();
    sprite = &entity->get_component<SpriteComponent>();
}

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

    if (keys[SDLK_a] > keys[SDLK_d]){
        transform->add_velocity(-2, 0);
    }

    if (keys[SDLK_d] > keys[SDLK_a]){
        transform->add_velocity(2, 0);
    }

    if (keys[SDLK_w] > keys[SDLK_s]){
        transform->add_velocity(0, -2);
    }

    if (keys[SDLK_s] > keys[SDLK_w]){
        transform->add_velocity(0, 2);
    }
}
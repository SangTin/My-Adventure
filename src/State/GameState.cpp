#include <State/GameState.hpp>

void GameState::init(){
    active = true;
}

bool GameState::is_active(){
    return active;
}

void GameState::destroy(){
    active = false;
}
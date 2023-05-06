#include <State/GameState.hpp>

void GameState::refresh(){
    manager.refresh();
}

void GameState::update(){
    manager.update();
}

void GameState::render(){
    manager.render();
}

bool GameState::is_active() const{
    return active;
}

void GameState::destroy(){
    active = false;
}
#include <State/GameState.hpp>
#include <Core/StateManager.hpp>

void GameState::refresh(){
    manager.refresh();
}

void GameState::update(){
    manager.update();
}

void GameState::render(){
    if (hidden) return;
    manager.render();
}

void GameState::lose_focus(){
    manager.lose_focus();
}

void GameState::gain_focus(){
    show();
    manager.gain_focus();
}

void GameState:: hide(){
    hidden = true;
    lose_focus();
}

void GameState:: show(){
    hidden = false;
}

bool GameState::is_active() const{
    return active;
}

void GameState::destroy(){
    active = false;
}
#include <algorithm> //remove_if
#include <Core/StateManager.hpp>
#include <Core/GameTimer.hpp>

std::vector<std::unique_ptr<GameState>> StateManager::states;

void StateManager::refresh(){
    states.erase(std::remove_if(std::begin(states), std::end(states), 
        [](std::unique_ptr<GameState> &mState)
    {
        if (mState->is_active()) return false;
        mState.reset();
        return true;
    }),
        std::end(states));
}

void StateManager::update(){
    GameTimer::update_timer();
    if (!states.empty()) {
        states.back()->gain_focus();
        states.back()->update();
    }
}

void StateManager::render(){
    for (auto& s : states){
        s->render();
    }
}

void StateManager::clear(){
    for (auto& s : states){
        s->destroy();
    }
}
#include <algorithm> //remove_if
#include <Core/StateManager.hpp>

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
    if (!states.empty()) {
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

void StateManager::clear_before(){
    for (int s = 0; s < (int)states.size() - 1; ++s){
        states[s]->destroy();
    }
}
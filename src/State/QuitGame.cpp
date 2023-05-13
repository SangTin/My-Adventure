#include <State/States.hpp>
#include <Core/Game.hpp>

void QuitGame::init(){
    Game::quit();
}
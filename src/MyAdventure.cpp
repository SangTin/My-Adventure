#include <iostream>
#include <Core/Base.hpp>
#include <Core/Game.hpp>
#include <Core/GameTimer.hpp>
#include <Core/Vector2D.hpp>
#include <State/States.hpp>

const int FPS = 144;
const int FPSTime = 1000.0 / FPS;

int main(int argc, char* argv[]){
    //Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << '\n';
        return -1;
    }

    //Initialize PNG loading
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)){
        std::cout << "IMG could not initialize! SDL_image Error: " << IMG_GetError() << '\n';
        return -1;
    }

    //Initialize SDL_mixer
    if (Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ){
        std::cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << '\n';
        return -1;
    }

    if (TTF_Init() < 0){
        std::cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << '\n';
        return -1;
    }

    static Game window("My Adventure", baseSquare * 30, baseSquare * 20);
    StateManager::add_state<Menu>();
    Mix_AllocateChannels(255);

    while (window.is_running()){
        window.handle_events();
        window.update();
        window.clear();
        window.render();

        if (GameTimer::get_DT() < FPSTime){
            SDL_Delay(FPSTime - GameTimer::get_DT());
        }
    }
    
    return 0;
}
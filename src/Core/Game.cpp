#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <Core/Game.hpp>
#include <UI/Mouse.hpp>
#include <Core/Managers.hpp>

SDL_Renderer* Game::renderer = NULL;
SDL_Window* Game::window = NULL;
SDL_Event Game::event;
SDL_Point Game::center;
TTF_Font* Game::font = NULL;

//Create game window named after title and size width x height (pixel)
Game::Game(const char* title, int width, int height)
    :running(true)
{
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (window == NULL){
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << '\n';
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL){
        std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << '\n';
    }
    SDL_SetRenderDrawColor(renderer, 33, 31, 48, 255);
    Mouse::init();
    font = FontManager::load_font("assets/font/prstartk.ttf");

    this->width = width;
    this->height = height;
    center = {width / 2, height / 2};
}

//Return game's status (running or not)
bool Game::is_running()const{
    return running;
}

//Change game window from windowed to fullscreen and vice versa
void Game::toggle_fullscreen(){
    Uint32 currentMode = SDL_GetWindowFlags(window);
    bool isFullscreen = (currentMode & SDL_WINDOW_FULLSCREEN_DESKTOP ? true : false);
    int Change = (isFullscreen ? 0 : SDL_WINDOW_FULLSCREEN_DESKTOP);
    SDL_SetWindowFullscreen(window, Change);
}

//Refresh and update all game objects
void Game::update(){
    Mouse::update();
    StateManager::update();
}

//Clear all game texture on the screen (renderer)
void Game::clear(){
    StateManager::refresh();
    SDL_RenderClear(renderer);
}

//Render all game objects to the screen (renderer)
void Game::render(){
    StateManager::render();
    SDL_RenderPresent(renderer);
}

//Handle events from keyboard and mouse
void Game::handle_events(){
    if (SDL_PollEvent(&event)){
        switch (event.type)
        {
        case SDL_QUIT:
            running = false;
            break;

        case SDL_WINDOWEVENT:
            if (event.window.event == SDL_WINDOWEVENT_FOCUS_GAINED){
                std::cout << "Continue!\n";
            }
            if (event.window.event == SDL_WINDOWEVENT_FOCUS_LOST){
                std::cout << "Pause!\n";
            }
            break;
        }
    }
}

//Close the game and release resources
void Game::close(){
    SDL_DestroyWindow(window);
    window = NULL;
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_Quit();
    IMG_Quit();
    Mix_Quit();
    TTF_Quit();
}
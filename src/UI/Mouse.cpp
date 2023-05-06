#include <UI/Mouse.hpp>
#include <iostream>
#include <SDL2/SDL_image.h>
using namespace Base;

mouseStats Mouse::mouseState;
Uint32 Mouse::mouseMask;
SDL_Point Mouse::position;
SDL_Cursor *Mouse::normal, *Mouse::pointing, *Mouse::holding;

//Initialize mouse cursor with several display types
void Mouse::init(){
    SDL_Surface* normalSurface = IMG_Load("assets/img/Mouse/Catpaw Mouse.png");
    normal = SDL_CreateColorCursor(normalSurface, 0, 0);
    SDL_FreeSurface(normalSurface);

    SDL_Surface* pointingSurface = IMG_Load("assets/img/Mouse/Catpaw pointing Mouse.png");
    pointing = SDL_CreateColorCursor(pointingSurface, 0, 0);
    SDL_FreeSurface(pointingSurface);

    SDL_Surface* holdingSurface = IMG_Load("assets/img/Mouse/Catpaw holding Mouse.png");
    holding = SDL_CreateColorCursor(holdingSurface, 0, 0);
    SDL_FreeSurface(holdingSurface);

    mouseState = mouseIdle;
}

/**
 * Add or remove the state of mouse cursor
 * \param mStat the state to be changed
 * \param sta add or remove it (true / false)
*/
void Mouse::change_mouse_state(mouseStats mStat){
    mouseState = std::min(mouseState, mStat);
}

/**
 * Get the state of mouse button
 * \param mButton the name of the button
*/
bool Mouse::get_button_state(int mButton){
    return (SDL_BUTTON(mouseMask) == mButton);
}

//Update the display of mouse cursor
void Mouse::update(){
    mouseMask = SDL_GetMouseState(&position.x, &position.y);
    
    if (mouseMask == SDL_BUTTON_LEFT){
        mouseState = std::min(mouseState, mouseHolding);
    }

    switch (mouseState)
    {
    case mouseIdle:
        SDL_SetCursor(normal);
        break;
    case mouseHolding:
        SDL_SetCursor(holding);
        break;
    case mousePointing:
        SDL_SetCursor(pointing);
        break;
    }

    mouseState = mouseIdle;
}

//Return current mouse's position
SDL_Point* Mouse::get_position(){
    return &position;
}
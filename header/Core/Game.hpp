#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

class Game{
    private:
        double width, height, scale;
        int disWidth, disHeight;
        bool running;
    public:
        static SDL_Renderer* renderer;
        static SDL_Window* window;
        static SDL_Event event;
        static SDL_Point center;

        Game(const char* title, int width, int height);
        ~Game();
        bool is_running()const;
        void toggle_fullscreen();
        void update();
        void clear();
        void render();
        void handle_events();
        void close();
};
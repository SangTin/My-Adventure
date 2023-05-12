#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

class Game{
    private:
        static int width, height;
        static double scale;
        static bool running;
    public:
        static SDL_Renderer* renderer;
        static SDL_Window* window;
        static SDL_Event event;
        static SDL_Point center;
        static TTF_Font* font;

        Game(const char* title, int width, int height);
        bool is_running();
        void toggle_fullscreen();
        void update();
        void clear();
        void render();
        void handle_events();
        void close();
        
        static bool is_key_down(const SDL_KeyCode key);
        static bool is_key_up(const SDL_KeyCode key);
        static void quit();
};
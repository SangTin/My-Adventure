#pragma once
#include <ECS/ECS.hpp>
#include <SDL2/SDL_mixer.h>
#include <map>
#include <string>

class Sound : public Component{
    private:
        std::map<std::string, Mix_Music*> music;
        std::map<std::string, Mix_Chunk*> sfx;
    public:
        Sound() = default;
        void add_music(const std::string name, const char* path);
        void add_music(const std::string name, Mix_Music* music);
        void play_music(const std::string name);
        void add_sound(const std::string name, const char* path);
        void add_sound(const std::string name, Mix_Chunk* sound);
        void play_sound(const std::string name);
};
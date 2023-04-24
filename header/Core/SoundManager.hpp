#pragma once
#include <SDL2/SDL_mixer.h>

class SoundManager{
    public:
        static int sfxVolume, musicVolume;

        static Mix_Music* load_music(const char* path);
        static Mix_Chunk* load_sound(const char* path);
        static void set_sfx_volume(int sfxVolume);
        static void set_music_volume(int musicVolume);
        static void play_music(Mix_Music* music);
        static void play_sound(Mix_Chunk* chunk);
        static void stop_music();
};
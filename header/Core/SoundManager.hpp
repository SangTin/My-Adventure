#pragma once
#include <SDL2/SDL_mixer.h>

class SoundManager{
    public:
        static double sfxVolume, musicVolume;
        static bool sfxMuted, musicMuted;

        static Mix_Music* load_music(const char* path);
        static Mix_Chunk* load_sound(const char* path);
        static void set_sfx_volume(double percent);
        static void set_music_volume(double percent);
        static int get_sfx_volume();
        static int get_music_volume();
        static void toggle_sfx_mute();
        static void toggle_music_mute();
        static void play_music(Mix_Music* music);
        static void play_sound(Mix_Chunk* chunk);
        static void stop_music();
};
#include <iostream>
#include <Core/SoundManager.hpp>

int SoundManager::sfxVolume = 100;
int SoundManager::musicVolume = 100;

/**
 * Load music from given path
 * \param f_path the path on the filesystem to load a music from
*/
Mix_Music* SoundManager::load_music(const char* f_path){
    Mix_Music* music = NULL;
    music = Mix_LoadMUS(f_path);
    if (music == NULL){
        std::cout << "Failed to load music " << f_path << "! SDL_mixer Error: " << Mix_GetError() << '\n';
    }
    return music;
}

/**
 * Load sound from given path
 * \param f_path the path on the filesystem to load a sound from
*/
Mix_Chunk* SoundManager::load_sound(const char* f_path){
    Mix_Chunk* sound = NULL;
    sound = Mix_LoadWAV(f_path);
    if (sound == NULL){
        std::cout << "Failed to load sound " << f_path << "! SDL_mixer Error: " << Mix_GetError() << '\n';
    }
    return sound;
}

/**
 * Set sfx volume
 * \param volume volume of the sound
*/
void SoundManager::set_sfx_volume(int volume){
    sfxVolume = (MIX_MAX_VOLUME * volume) / 100;
}

/**
 * Set music volume
 * \param volume volume of the music
*/
void SoundManager::set_music_volume(int volume){
    musicVolume = (MIX_MAX_VOLUME * volume) / 100;
    Mix_VolumeMusic(musicVolume);
}

/**
 * Play music passed in
 * \param music the source music
*/
void SoundManager::play_music(Mix_Music* music){
    Mix_VolumeMusic(musicVolume);
    Mix_PlayMusic(music, -1);
}

/**
 * Play sound passed in
 * \param sound the source sound
*/
void SoundManager::play_sound(Mix_Chunk* sound){
    Mix_VolumeChunk(sound, sfxVolume);
    Mix_PlayChannel(-1, sound, 0);
}

void SoundManager::stop_music(){
    Mix_HaltMusic();
}
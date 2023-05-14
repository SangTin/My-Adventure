#include <iostream>
#include <Core/SoundManager.hpp>

double SoundManager::sfxVolume = MIX_MAX_VOLUME;
double SoundManager::musicVolume = MIX_MAX_VOLUME;
bool SoundManager::sfxMuted = false;
bool SoundManager::musicMuted = false;

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
void SoundManager::set_sfx_volume(double percent){
    sfxMuted = (percent == 0);
    sfxVolume = (MIX_MAX_VOLUME * percent) / 100;
}

/**
 * Set music volume
 * \param volume volume of the music
*/
void SoundManager::set_music_volume(double percent){
    musicMuted = (percent == 0);
    musicVolume = (MIX_MAX_VOLUME * percent) / 100;
    Mix_VolumeMusic(musicVolume);
}

int SoundManager::get_sfx_volume(){
    if (sfxMuted) return 0;
    return (sfxVolume * 100 / MIX_MAX_VOLUME);
}

int SoundManager::get_music_volume(){
    if (musicMuted) return 0;
    return (musicVolume * 100 / MIX_MAX_VOLUME);
}

void SoundManager::toggle_sfx_mute(){
    sfxMuted = !sfxMuted;
    if (!sfxMuted){
        double min = (MIX_MAX_VOLUME * 1.0) / 100;
        sfxVolume = std::max(sfxVolume, min);
    }
}

void SoundManager::toggle_music_mute(){
    musicMuted = !musicMuted;
    if (!musicMuted){
        double min = (MIX_MAX_VOLUME * 1.0) / 100;
        musicVolume = std::max(musicVolume, min);
    }
    Mix_VolumeMusic(musicVolume * !musicMuted);
}

bool SoundManager::sfx_is_muted(){
    return sfxMuted;
}

bool SoundManager::music_is_muted(){
    return musicMuted;
}

/**
 * Play music passed in
 * \param music the source music
*/
void SoundManager::play_music(Mix_Music* music){
    Mix_VolumeMusic(musicVolume * !musicMuted);
    Mix_PlayMusic(music, -1);
}

/**
 * Play sound passed in
 * \param sound the source sound
*/
void SoundManager::play_sound(Mix_Chunk* sound){
    Mix_VolumeChunk(sound, sfxVolume * !sfxMuted);
    Mix_PlayChannel(-1, sound, 0);
}

void SoundManager::stop_music(){
    Mix_HaltMusic();
}
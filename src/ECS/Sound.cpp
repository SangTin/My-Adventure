#include <ECS/Sound.hpp>
#include <Core/SoundManager.hpp>

using namespace std;

void Sound::add_music(const string name, const char* path){
    music.emplace(name, SoundManager::load_music(path));
}

void Sound::add_music(const string name, Mix_Music* music){
    this->music.emplace(name, music);
}

void Sound::play_music(const string name){
    if (music.find(name) == music.end()){
        cout << "Invalid music name: " << name << "!\n";
        return;
    }
    SoundManager::play_music(music[name]);
}

void Sound::add_sound(const string name, const char* path){
    sfx.emplace(name, SoundManager::load_sound(path));
}

void Sound::add_sound(const string name, Mix_Chunk* sound){
    this->sfx.emplace(name, sound);
}

#include <typeinfo>
#include <cstring>
void Sound::play_sound(const string name){
    if (sfx.find(name) == sfx.end()){
        cout << "Invalid sound name: " << name << "!\n";
        return;
    }
    SoundManager::play_sound(sfx[name]);
}
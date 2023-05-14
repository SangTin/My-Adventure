#include <State/States.hpp>
#include <Core/HandleEvent.hpp>
#include <string>
#include <charconv> //to_chars
#include <math.h> //log10

#define SCALE 2

const char* level_path = "data/Level_00.json";

Play::Play(int level){
    int numLen = log10(level) + 1;
    std::string path = level_path;
    std::to_chars(path.data() + path.size() - 5 - numLen, path.data() + path.size() - 5, level);
}

void Play::init(){
    StateManager::clear_before();
    Pause = &manager.add_entity<ClickedButton>("assets/img/button/PauseButton.png", 10, 10, 24, 26, SCALE);

    //Add sound
    for (auto& b : manager.get_group(Base::groupButtons)){
        b->add_sound("Hover", "assets/sound/menu/MenuHover.mp3");
        b->add_sound("Pressed", "assets/sound/menu/MenuPressed.mp3");
    }
}

void Play::update(){
    GameState::update();
    if (HandleEvent::lose_focus() || HandleEvent::get_key_down(SDL_SCANCODE_ESCAPE) || Pause->is_pressed()) pause();
}

void Play::pause(){
    StateManager::add_state<PauseMenu>();
}
#include <State/States.hpp>
#include <Core/SoundManager.hpp>
#include <Core/Game.hpp>

void Menu::init(){
    Play = &manager.add_entity<ClickedButton>("assets/img/button/PlayButton.png", 0, 0, 92, 29, 2);
    Play->centered();

    Option = &manager.add_entity<ClickedButton>("assets/img/button/OptionButton.png", 0, 58, 92, 29, 2);
    Option->centered();

    Quit = &manager.add_entity<ClickedButton>("assets/img/button/QuitButton.png", 0, 116, 92, 29, 2);
    Quit->centered();

    //Add sound
    for (auto& b : manager.get_group(Base::groupButtons)){
        b->add_sound("Hover", "assets/sound/menu/MenuHover.mp3");
        b->add_sound("Pressed", "assets/sound/menu/MenuPressed.mp3");
    }
    
    //Soundtrack: Valorant-Bazooka-Badger-Theme.mp3
    soundtrack = SoundManager::load_music("assets/sound/menu/Valorant-Bazooka-Badger-Theme.mp3");
    SoundManager::play_music(soundtrack);
}

void Menu::update(){
    show();
    GameState::update();
    if (Play->is_pressed()) play();
    if (Option->is_pressed()) option();
    if (Game::is_key_down(SDLK_ESCAPE) || Quit->is_pressed()) quit();

}

void Menu::destroy(){
    GameState::destroy();
    SoundManager::stop_music();
}

void Menu::play(){
    hide();
    StateManager::add_state<LevelsMenu>();
}

void Menu::quit(){
    hide();
    StateManager::add_state<QuitDialouge>();
}

void Menu::option(){
    hide();
    StateManager::add_state<OptionMenu>();
}
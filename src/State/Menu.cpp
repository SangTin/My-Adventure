#include <State/States.hpp>
#include <Core/SoundManager.hpp>
#include <Core/HandleEvent.hpp>
#include <State/Dialouge.hpp>

void Menu::init(){
    StateManager::clear_before();

    Play = &manager.add_entity<ClickedButton>("assets/img/button/BigPlayButton.png", 0, 0, 92, 29, 2);
    Play->centered();

    Option = &manager.add_entity<ClickedButton>("assets/img/button/BigOptionButton.png", 0, 58, 92, 29, 2);
    Option->centered();

    Quit = &manager.add_entity<ClickedButton>("assets/img/button/BigQuitButton.png", 0, 116, 92, 29, 2);
    Quit->centered();

    //Add sound
    for (auto& b : manager.get_group(Base::groupButtons)){
        b->add_sound("Hover", "assets/sound/menu/MenuHover.mp3");
        b->add_sound("Pressed", "assets/sound/menu/MenuPressed.mp3");
    }
    
    //Set volume
    SoundManager::set_music_volume(50);
    SoundManager::set_sfx_volume(50);

    //Soundtrack: Valorant-Bazooka-Badger-Theme.mp3
    soundtrack = SoundManager::load_music("assets/sound/menu/Valorant-Bazooka-Badger-Theme.mp3");
    SoundManager::play_music(soundtrack);

    testPlayer = &manager.add_entity<Player>(0, 0, 32, 32, 2);
}

void Menu::update(){
    show();
    GameState::update();
    if (Play->is_pressed()) play();
    if (Option->is_pressed()) option();
    if (HandleEvent::get_key_down(SDL_SCANCODE_ESCAPE) || Quit->is_pressed()) quit();

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
    StateManager::add_state<Dialouge<QuitGame>>("Are you sure you want to exit the game?");
}

void Menu::option(){
    hide();
    StateManager::add_state<OptionMenu>();
}
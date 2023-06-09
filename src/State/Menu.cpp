#include <State/States.hpp>
#include <Core/SoundManager.hpp>
#include <Core/HandleEvent.hpp>
#include <State/Dialouge.hpp>

#define SCALE 1
#define BG_WIDTH 1920
#define BG_HEIGHT 1080

void Menu::init(){
    StateManager::clear_before();
    background = &manager.add_entity<Entity>();
    transform = &background->add_component<TransformComponent>(0, 0, Game::get_screen_width(), Game::get_screen_height(), SCALE);
    background->add_component<SpriteComponent>("assets/img/states/Menu/GameBackground.png", BG_WIDTH, BG_HEIGHT);

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

    //Soundtrack: Valorant-Bazooka-Badger-Theme.mp3
    soundtrack = SoundManager::load_music("assets/sound/menu/Valorant-Bazooka-Badger-Theme.mp3");
    SoundManager::play_music(soundtrack);
}

void Menu::update(){
    show();
    GameState::update();
    if (Play->is_pressed()) play();
    if (Option->is_pressed()) option();
    if (HandleEvent::is_key_pressed(SDLK_ESCAPE) || Quit->is_pressed()) quit();
}

void Menu::render(){
    background->render();
    if (hidden) return;
    manager.render();
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
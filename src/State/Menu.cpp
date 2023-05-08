#include <State/States.hpp>

void Menu::init(){
    Play = &Components::create_clicked_button(manager, "assets/img/button/PlayButton.png", 0, 0, 92, 29, 2, true);
    Option = &Components::create_clicked_button(manager, "assets/img/button/OptionButton.png", 0, 58, 92, 29, 2, true);
    Quit = &Components::create_clicked_button(manager, "assets/img/button/QuitButton.png", 0, 116, 92, 29, 2, true);

    buttons.emplace_back(Play);
    buttons.emplace_back(Option);
    buttons.emplace_back(Quit);

    //Add sound
    for (auto& b : buttons){
        b->add_sound("Hover", "assets/sound/menu/MenuHover.mp3");
        b->add_sound("Pressed", "assets/sound/menu/MenuPressed.mp3");
    }
}

void Menu::update(){
    GameState::update();
    if (Play->is_pressed()) play();
}

void Menu::play(){
    hide();
    StateManager::add_state<LevelsMenu>();
}
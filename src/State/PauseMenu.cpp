#include <State/States.hpp>
#include <Core/HandleEvent.hpp>
#include <State/Dialouge.hpp>

#define SCALE 3
#define BG_WIDTH 124
#define BG_HEIGHT 129

void PauseMenu::init(){
    background = &manager.add_entity<Entity>();
    transform = &background->add_component<TransformComponent>(0, 0, BG_WIDTH, BG_HEIGHT, SCALE);
    transform->centered();
    background->add_component<SpriteComponent>("assets/img/states/Pause/Pause.png", BG_WIDTH, BG_HEIGHT);

    const int BUTTON_X = transform->dst.x + 16 * SCALE;
    const int BUTTON_Y = transform->dst.y + 44 * SCALE;

    Continue = &manager.add_entity<ClickedButton>("assets/img/button/BigContinueButton.png", BUTTON_X, BUTTON_Y, 92, 29, SCALE);
    Home = &manager.add_entity<ClickedButton>("assets/img/button/HomeButton.png", BUTTON_X, BUTTON_Y + 35 * SCALE, 24, 26, SCALE);
    Option = &manager.add_entity<ClickedButton>("assets/img/button/OptionButton.png", BUTTON_X + 34 * SCALE, BUTTON_Y + 35 * SCALE, 24, 26, SCALE);
    Quit = &manager.add_entity<ClickedButton>("assets/img/button/QuitButton.png", BUTTON_X + 68 * SCALE, BUTTON_Y + 35 * SCALE, 24, 26, SCALE);

    //Add sound
    for (auto& b : manager.get_group(Base::groupButtons)){
        b->add_sound("Hover", "assets/sound/menu/MenuHover.mp3");
        b->add_sound("Pressed", "assets/sound/menu/MenuPressed.mp3");
    }
}

void PauseMenu::update(){
    show();
    GameState::update();
    if (Home->is_pressed()) home();
    if (Option->is_pressed()) option();
    if (Quit->is_pressed()) quit();
    if (HandleEvent::is_key_pressed(SDLK_ESCAPE) || Continue->is_pressed()) play();
}

void PauseMenu::play(){
    destroy();
}

void PauseMenu::home(){
    hide();
    StateManager::add_state<Dialouge<Menu>>("Are you sure you want to exit to the main menu?");
}

void PauseMenu::option(){
    hide();
    StateManager::add_state<OptionMenu>();
}

void PauseMenu::quit(){
    hide();
    StateManager::add_state<Dialouge<QuitGame>>("Are you sure you want to exit the game?");
}
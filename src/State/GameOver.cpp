#include <State/GameOver.hpp>
#include <State/States.hpp>
#include <Core/Game.hpp>
#include <Core/SoundManager.hpp>

#define SCALE 1
#define BG_WIDTH 417
#define BG_HEIGHT 160
#define BUTTON_SCALE 3
#define BUTTON_WIDTH 92
#define BUTTON_HEIGHT 29

void GameOver::init(){
    background = &manager.add_entity<Entity>();
    transform = &background->add_component<TransformComponent>(0, -50, BG_WIDTH, BG_HEIGHT, SCALE);
    transform->centered();
    background->add_component<SpriteComponent>("assets/img/states/GameOver/GameOver.png", BG_WIDTH, BG_HEIGHT);

    const int BUTTON_X = (Game::get_screen_width() - (BUTTON_WIDTH * BUTTON_SCALE)) / 2;
    const int BUTTON_Y = (Game::get_screen_height() - (BUTTON_HEIGHT * BUTTON_SCALE)) / 2 + 100;

    Continue = &manager.add_entity<ClickedButton>("assets/img/button/BigContinueButton.png", BUTTON_X, BUTTON_Y, BUTTON_WIDTH, BUTTON_HEIGHT, BUTTON_SCALE);

    //Soundtrack
    soundtrack = SoundManager::load_music("assets/sound/menu/GameOver.mp3");
    SoundManager::play_music(soundtrack);
}

void GameOver::update(){
    GameState::update();
    if (Continue->is_pressed()) play();
}

void GameOver::play(){
    SoundManager::stop_music();
    StateManager::add_state<Menu>();
}
#include <State/States.hpp>
#include <Core/Game.hpp>
#include <Core/TextureManager.hpp>
#include <math.h> //log10
#include <string>

#define SCALE 3
#define BG_WIDTH 265
#define BG_HEIGHT 128

//Level buttons info
#define LEVEL_ROWS 5
#define LEVEL_COLUMN 1
#define LEVEL_W 20
#define LEVEL_H 21

void LevelsMenu::init(){
    background = &manager.add_entity<Entity>();
    transform = &background->add_component<TransformComponent>(0, 0, BG_WIDTH, BG_HEIGHT, SCALE);
    transform->centered();
    background->add_component<SpriteComponent>("assets/img/states/Levels/Levels.png", BG_WIDTH, BG_HEIGHT);

    char path[] = "assets/img/states/Levels/LevelButton.png";
    const int LEVEL_X = transform->dst.x + 20 * transform->scale;
    const int LEVEL_Y = transform->dst.y + 42 * transform->scale;

    for (int r = 0; r < LEVEL_ROWS; ++r){
        for (int c = 0; c < LEVEL_COLUMN; ++c){
            int x = LEVEL_X + r * (LEVEL_W + 4) * SCALE;
            int y = LEVEL_Y + c * (LEVEL_H + 4) * SCALE;

            levels.emplace_back(&manager.add_entity<ClickedButton>(path, x, y, LEVEL_W, LEVEL_H, SCALE));
            
            levels.back()->add_sound("Hover", "assets/sound/menu/MenuHover.mp3");
            levels.back()->add_sound("Pressed", "assets/sound/menu/MenuPressed.mp3");
        }
    }
}

void LevelsMenu::update(){
    GameState::update();
    if (Game::is_key_down(SDLK_ESCAPE)){
        destroy();
    }
    for (int r = 0; r < LEVEL_ROWS; ++r){
        for (int c = 0; c < LEVEL_COLUMN; ++c){
            int cur_lv = r * LEVEL_COLUMN + c;
            if (levels[cur_lv]->is_pressed()){
                StateManager::add_state<Play>(cur_lv + 1);
            }
        }
    }
}
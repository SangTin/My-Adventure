#include <State/States.hpp>
#include <Core/HandleEvent.hpp>
#include <string>
#include <charconv> //to_chars
#include <math.h> //log10
#include <UI/Camera.hpp>
#include <Core/SoundManager.hpp>

#define SCALE 2

const char* level_path = "data/map/Level_00.json";

Player *Play::player;

Play::Play(int level){
    int numLen = log10(level) + 1;
    std::string path = level_path;
    std::to_chars(path.data() + path.size() - 5 - numLen, path.data() + path.size() - 5, level);

    map.init(path);
    
    //Spawn player
    SDL_Point playerPoint = map.get_player_spawn();
    player = &manager.add_entity<Player>(playerPoint.x * TILE_SCALE, playerPoint.y * TILE_SCALE, 32, 32, 3);
    Camera::set_target(player->get_origin());
}

Play::~Play(){
    Camera::set_target(nullptr);
    delete GameMap::manager;
}

void Play::init(){
    StateManager::clear_before();
    Pause = &manager.add_entity<ClickedButton>("assets/img/button/PauseButton.png", 10, 10, 24, 26, SCALE);

    //Add sound
    for (auto& b : manager.get_group(Base::groupButtons)){
        b->add_sound("Hover", "assets/sound/menu/MenuHover.mp3");
        b->add_sound("Pressed", "assets/sound/menu/MenuPressed.mp3");
    }

    //Soundtrack: Bit Rush Arcade.mp3
    soundtrack = SoundManager::load_music("assets/sound/playing/Bit Rush Arcade.mp3");
    SoundManager::play_music(soundtrack);

    manager.add_entity<HealthAndScore>(3);
}

void Play::update(){
    GameState::update();
    Camera::update();
    map.update();
    if (HandleEvent::lose_focus() || HandleEvent::is_key_pressed(SDLK_ESCAPE) || Pause->is_pressed()) pause();
    if (player->is_dead()) gameover();
}

void Play::render(){
    map.render();
    GameState::render();
}

void Play::pause(){
    StateManager::add_state<PauseMenu>();
}

void Play::gameover(){
    SoundManager::stop_music();
    StateManager::add_state<GameOver>();
}
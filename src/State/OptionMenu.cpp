#include <State/States.hpp>
#include <Core/Base.hpp>
#include <Core/HandleEvent.hpp>
#include <Core/SoundManager.hpp>
#include <UI/Mouse.hpp>

#define SCALE 0.75
#define BG_WIDTH 447
#define BG_HEIGHT 600

#define NUM_STEPS 25
#define STEPS_HEIGHT 12
#define STEPS_WIDTH 5
#define STEPS_SCALE 1.25

void OptionMenu::init(){
    background = &manager.add_entity<Entity>();
    transform = &background->add_component<TransformComponent>(0, 0, BG_WIDTH, BG_HEIGHT, SCALE);
    transform->centered();
    background->add_component<SpriteComponent>("assets/img/states/Option/Settings.png", BG_WIDTH, BG_HEIGHT);

    int BUTTON_X = transform->dst.x;
    int BUTTON_Y = transform->dst.y;
    
    music = &manager.add_entity<ClickedButton>("assets/img/button/MusicToggle.png", BUTTON_X + 49 * SCALE, BUTTON_Y + 132 * SCALE, 96, 42, 1);
    SDL_Rect musicDst = music->get_dst();
    SDL_Rect slider;
    slider.w = STEPS_WIDTH * NUM_STEPS;
    slider.h = STEPS_HEIGHT;
    slider.x = BUTTON_X + transform->dst.w - 49 * SCALE - slider.w * STEPS_SCALE;
    slider.y = musicDst.y + (musicDst.h - slider.h) / 2;
    musicVolume = &manager.add_entity<Slider>(Base::musicID, slider.x, slider.y, slider.w, slider.h, STEPS_SCALE, NUM_STEPS);

    sfx = &manager.add_entity<ClickedButton>("assets/img/button/SFXToggle.png", musicDst.x, musicDst.y + musicDst.h + 10, 96, 42, 1);
    SDL_Rect sfxDst = sfx->get_dst();
    slider.y = sfxDst.y + (sfxDst.h - slider.h) / 2;
    sfxVolume = &manager.add_entity<Slider>(Base::sfxID, slider.x, slider.y, slider.w, slider.h, STEPS_SCALE, NUM_STEPS);
    sfxSound = SoundManager::load_sound("assets/sound/menu/MenuHover.mp3");
}

void OptionMenu::update(){
    int sfxVolumeOld = SoundManager::get_sfx_volume();
    GameState::update();
    if (HandleEvent::is_key_pressed(SDLK_ESCAPE)){
        destroy();
    }
    if (Mouse::get_button_state(SDL_BUTTON_LEFT) && !SDL_PointInRect( Mouse::get_position(), &transform->dst )){
        destroy();
    }
    music->change_frameY(SoundManager::music_is_muted());
    if (music->is_pressed()){
        SoundManager::toggle_music_mute();
    }
    sfx->change_frameY(SoundManager::sfx_is_muted());
    if (sfx->is_pressed()){
        SoundManager::toggle_sfx_mute();
    }
    int sfxVolumeNew = SoundManager::get_sfx_volume();
    if (sfxVolumeOld != sfxVolumeNew){
        SoundManager::play_sound(sfxSound);
    }
}
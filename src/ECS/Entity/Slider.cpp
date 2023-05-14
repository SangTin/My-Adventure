#include <ECS/Entity/Slider.hpp>
#include <Core/TextureManager.hpp>
#include <Core/SoundManager.hpp>
#include <UI/Mouse.hpp>
#include <math.h> //ceil

//Start class Step
Step::Step(SDL_Texture *texture, SDL_Rect dst){
    this->texture = texture;
    this->dst = dst;
    this->src = {0, 0, 5, 12};
}

void Step::render(){
    if (isActivated) src.x = 5;
    else src.x = 0;
    TextureManager::draw(texture, &src, &dst);
}
//End class Step

//Start class Slider
Slider::Slider(sliderType type, SDL_Rect dst, double scale, int numSteps){
    this->type = type;
    this->numSteps = numSteps;
    init_transform(dst.x, dst.y, dst.w, dst.h, scale);
    init_steps();
}

Slider::Slider(sliderType type, int x, int y, int width, int height, double scale, int numSteps){
    this->type = type;
    this->numSteps = numSteps;
    init_transform(x, y, width, height, scale);
    init_steps();
}

void Slider::update(){
    Button::update();
    SDL_Point mPt = *Mouse::get_position();
    SDL_Rect& sliderRect = transform->dst;
    
    const double stepPercent = 100.0 / numSteps;
    int percent, curStep;
    if (SDL_PointInRect(&mPt, &sliderRect ) && Mouse::get_button_state(SDL_BUTTON_LEFT)){
        const double fx = mPt.x - sliderRect.x;
        percent = ceil(fx / sliderRect.w * 100);

        curStep = (percent + stepPercent - 1) / stepPercent;
        switch (type)
        {
        case sfxID:
            SoundManager::set_sfx_volume(stepPercent * curStep);
            break;
        
        case musicID:
            SoundManager::set_music_volume(stepPercent * curStep);
            break;
        }
    }
    else{
        switch (type)
        {
        case sfxID:
            percent = SoundManager::get_sfx_volume();
            curStep = (percent + stepPercent - 1) / stepPercent;
            SoundManager::set_sfx_volume(stepPercent * curStep);
            break;
        
        case musicID:
            percent = SoundManager::get_music_volume();
            curStep = (percent + stepPercent - 1) / stepPercent;
            SoundManager::set_music_volume(stepPercent * curStep);
            break;
        }
    }
    
    for (int i = 0; i < numSteps; ++i){
        steps[i].isActivated = (i < curStep);
    }
}

void Slider::render(){
    Button::render();
    for (auto& s : steps) s.render();
}

void Slider::init_steps(){
    steps.resize(numSteps);
    SDL_Rect baseDst = transform->dst;

    int x = baseDst.x;
    const int y = baseDst.y;
    const int height = baseDst.h;
    const int width = baseDst.w / numSteps;

    SDL_Texture* stepTexture = TextureManager::load_texture("assets/img/button/SliderStep.png");

    for (auto& s : steps){
        s = Step(stepTexture, {x, y, width, height});
        x += width;
    }
}
//End class Slider
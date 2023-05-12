#pragma once
#include "Button.hpp"
#include <vector>
#include <SDL2/SDL.h>
#include <Core/Base.hpp>

using namespace Base;

struct Step{
    SDL_Texture* texture;
    SDL_Rect src, dst;
    bool isActivated = false;

    Step() = default;
    Step(SDL_Texture* texture, SDL_Rect dst);

    void render();
};  

class Slider : public Button{
    private:
        sliderType type = sliderNan;
        int numSteps = 0;
        std::vector<Step> steps;

    public:
        Slider(sliderType type, SDL_Rect dst, double scale, int numSteps);
        Slider(sliderType type, int x, int y, int width, int height, double scale, int numSteps);

        void update() override;
        void render() override;

    private:
        void init_steps();
};
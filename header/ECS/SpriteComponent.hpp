#pragma once
#include <SDL2/SDL.h>
#include "ECS.hpp"
#include "TransformComponent.hpp"

class SpriteComponent : public Component{
    protected:
        TransformComponent* transform;
        SDL_Texture* texture;
    public:
        SDL_Rect src;
        SDL_RendererFlip flip;

    public:
        SpriteComponent(const char* path, int width, int height);
        ~SpriteComponent();
        void init() override;
        void render() override;
};
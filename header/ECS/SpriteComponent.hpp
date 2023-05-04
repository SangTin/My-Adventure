#pragma once
#include <SDL2/SDL.h>
#include "ECS.hpp"
#include "TransformComponent.hpp"

class SpriteComponent : public Component{
    private:
        TransformComponent* transform;
        SDL_Texture* texture;
        SDL_Rect src, dst;
        SDL_RendererFlip flip;
    public:
        SpriteComponent() = default;
        SpriteComponent(const char* path);
        ~SpriteComponent();
        void init() override;
        void update() override;
        void render() override;
};
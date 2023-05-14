#pragma once
#include <ECS/ECS.hpp>
#include <SDL2/SDL.h>
#include "TransformComponent.hpp"

class SpriteComponent : public Component{
    protected:
        TransformComponent* transform;
        SDL_Texture* texture = nullptr;
    public:
        SDL_Rect src;
        SDL_RendererFlip flip = SDL_FLIP_NONE;

    public:
        SpriteComponent() = default;
        SpriteComponent(const char* path, int width, int height);
        virtual ~SpriteComponent();
        void init() override;
        void render() override;
        SDL_Texture* get_texture();
};
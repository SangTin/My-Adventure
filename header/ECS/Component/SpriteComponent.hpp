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
        bool toCamera = false;

    public:
        SpriteComponent() = default;
        SpriteComponent(const char* path, int width, int height, bool toCamera = false);
        SpriteComponent(SDL_Texture* texture, int width, int height, bool toCamera = false);
        SpriteComponent(SDL_Texture* texture, SDL_Rect src, bool toCamera = false);
        virtual ~SpriteComponent();
        void init() override;
        void render() override;
        SDL_Texture* get_texture();
};
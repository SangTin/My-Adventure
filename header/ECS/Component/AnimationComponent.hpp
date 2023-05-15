#pragma once
#include <ECS/ECS.hpp>
#include "TransformComponent.hpp"
#include "SpriteComponent.hpp"
#include <SDL2/SDL.h>
#include <map>
#include <string>

struct Animation{
    SDL_Texture* texture;
    int frameCount;

    Animation(){}
    Animation(SDL_Texture* mTexture, int frames)
        : texture(mTexture), frameCount(frames){}
    ~Animation(){
        SDL_DestroyTexture(texture);
    }
};

class AnimationComponent : public SpriteComponent{
    private:
        TransformComponent* transform;
        std::map<std::string, Animation*> animations;
        int frameSpeed, frameCount;

    public:
        AnimationComponent(int width, int height, bool toCamera = false);
        virtual ~AnimationComponent();
        void init() override;
        void update() override;
        void render() override;
        void add_animation(const std::string name, SDL_Texture* texture);
        void add_animation(const std::string name, const char* path);
        void play(const std::string name, int fSpeed, int flip = -1);
};
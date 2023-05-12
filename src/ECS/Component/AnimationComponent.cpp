#include <ECS/Component/AnimationComponent.hpp>
#include <Core/TextureManager.hpp>

AnimationComponent::AnimationComponent(int width, int height){
    src = {0, 0, width, height};
}

AnimationComponent::~AnimationComponent(){
    for (auto& a : animations){
        delete a.second;
    }
}

void AnimationComponent::init(){
    transform = &entity->get_component<TransformComponent>();
}

void AnimationComponent::update(){
    if (!texture) return;
    src.x = src.w * static_cast<int>((SDL_GetTicks() / frameSpeed) % frameCount);
}

void AnimationComponent::render(){
    if (!texture) return;
    TextureManager::draw(texture, &src, &transform->dst, flip);
}

void AnimationComponent::add_animation(const std::string name, SDL_Texture* texture, int frames, int fSpeed){
    animations.emplace(name, new Animation(texture, frames, fSpeed));
}

void AnimationComponent::add_animation(const std::string name, const char* path, int frames, int fSpeed){
    SDL_Texture* texture = TextureManager::load_texture(path);
    add_animation(name, texture, frames, fSpeed);
}

void AnimationComponent::play(const std::string name){
    if (animations.find(name) == animations.end()){
        std::cout << "Invalid animation: " << name << '\n';
        return;
    }
    texture = animations[name]->texture;
    frameSpeed = animations[name]->frameSpeed;
    frameCount = animations[name]->frameCount;
}
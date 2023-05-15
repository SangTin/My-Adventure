#include <ECS/Component/AnimationComponent.hpp>
#include <Core/TextureManager.hpp>

AnimationComponent::AnimationComponent(int width, int height, bool toCamera){
    src = {0, 0, width, height};
    this->toCamera = toCamera;
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
    TextureManager::draw(texture, &src, &transform->dst, toCamera, flip);
}

void AnimationComponent::add_animation(const std::string name, SDL_Texture* texture){
    int textureWidth;
    SDL_QueryTexture(texture, NULL, NULL, &textureWidth, NULL);
    int frames = textureWidth / src.w;
    animations.emplace(name, new Animation(texture, frames));
}

void AnimationComponent::add_animation(const std::string name, const char* path){
    SDL_Texture* texture = TextureManager::load_texture(path);
    add_animation(name, texture);
}

void AnimationComponent::play(const std::string name, int fSpeed, int flip){
    if (animations.find(name) == animations.end()){
        std::cout << "Invalid animation: " << name << '\n';
        return;
    }
    texture = animations[name]->texture;
    frameSpeed = fSpeed;
    frameCount = animations[name]->frameCount;
    if (flip != -1) this->flip = static_cast<SDL_RendererFlip>(flip);
    if (src.x / src.w + 1 > frameCount) src.x = 0;
}
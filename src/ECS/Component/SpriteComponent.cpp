#include <ECS/Component/SpriteComponent.hpp>
#include <Core/TextureManager.hpp>

SpriteComponent::SpriteComponent(const char* path, int width, int height, bool toCamera){
    texture = TextureManager::load_texture(path);
    src = {0, 0, width, height};
    this->toCamera = toCamera;
}

SpriteComponent::SpriteComponent(SDL_Texture* texture, int width, int height, bool toCamera){
    this->texture = texture;
    src = {0, 0, width, height};
    this->toCamera = toCamera;
}

SpriteComponent::SpriteComponent(SDL_Texture* texture, SDL_Rect src, bool toCamera){
    this->texture = texture;
    this->src = src;
    this->toCamera = toCamera;
}

SpriteComponent::~SpriteComponent(){
    SDL_DestroyTexture(texture);
}

void SpriteComponent::init(){
    transform = &entity->get_component<TransformComponent>();
}

void SpriteComponent::render(){
    TextureManager::draw(texture, &src, &transform->dst, toCamera, flip);
}

SDL_Texture* SpriteComponent::get_texture(){
    return texture;
}
#include <ECS/Component/SpriteComponent.hpp>
#include <Core/TextureManager.hpp>

SpriteComponent::SpriteComponent(const char* path, int width, int height){
    texture = TextureManager::load_texture(path);
    src = {0, 0, width, height};
}

SpriteComponent::~SpriteComponent(){
    SDL_DestroyTexture(texture);
}

void SpriteComponent::init(){
    transform = &entity->get_component<TransformComponent>();
}

void SpriteComponent::render(){
    TextureManager::draw(texture, &src, &transform->dst, flip);
}
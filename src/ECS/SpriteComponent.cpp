#include <ECS/SpriteComponent.hpp>
#include <Core/TextureManager.hpp>

SpriteComponent::SpriteComponent(const char* path){
    texture = TextureManager::load_texture(path);
}

SpriteComponent::~SpriteComponent(){
    SDL_DestroyTexture(texture);
}

void SpriteComponent::init(){
    transform = &entity->get_component<TransformComponent>();

    src.x = src.y = 0;
    dst.x = dst.y = 0;
    flip = SDL_FLIP_NONE;
}

void SpriteComponent::update(){
    dst.x = transform->get_x();
    dst.y = transform->get_y();
}

void SpriteComponent::render(){
    TextureManager::draw(texture, &src, &dst, flip);
}
#include <ECS/Components.hpp>
#include <Core/Game.hpp>

ClickedButton& Components::create_clicked_button(EnityManager& manager, const char* path, int x, int y, int width, int height, double scale, bool centered){
    Entity* entity = manager.add_entity();
    TransformComponent* transform = &entity->add_component<TransformComponent>(x, y, width, height, scale);
    if (centered){
        transform->centered();
    }
    entity->add_component<SpriteComponent>(path, width, height);
    entity->add_component<Sound>();
    return entity->add_component<ClickedButton>();
}
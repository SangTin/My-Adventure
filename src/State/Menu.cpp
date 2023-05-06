#include <State/Menu.hpp>
#include <ECS/Components.hpp>

Entity* Menu::create_button(const char* path, int x, int y, int width, int height, double scale){
    Entity& entity(manager.add_entity());
    entity.add_component<TransformComponent>(x, y, width, height, scale);
    entity.add_component<SpriteComponent>(path, width, height);
    entity.add_component<ClickedButton>();
    return &entity;
}

void Menu::init(){
    Play = create_button("assets/img/button/PlayButton.png", 0, 0, 92, 29, 2);
    Option = create_button("assets/img/button/PlayButton.png", 0, 58, 92, 29, 2);
    Quit = create_button("assets/img/button/PlayButton.png", 0, 116, 92, 29, 2);
}
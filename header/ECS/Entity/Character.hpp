#pragma once
#include <ECS/Component/Components.hpp>
#include <ECS/Entity/Entities.hpp>

class Character : public Entity{
    private:
        TransformComponent* transform;
        AnimationComponent* animation;

    public:
        Character(int x, int y, int width, int height, double scale);

        void add_action(const std::string name, const char* path, int frames, int speed = 150);
        void play_action(const std::string name);
};
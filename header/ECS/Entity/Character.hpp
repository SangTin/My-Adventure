#pragma once
#include <ECS/Component/Components.hpp>

class Character : public Entity{
    protected:
        TransformComponent* transform;
        AnimationComponent* animation;
        bool action = false;

    public:
        Character() = default;
        Character(int x, int y, int width, int height, double scale);

        void add_action(const std::string name, const char* path);
        void play_action(const std::string name, int fSpeed, int flip = -1);
};
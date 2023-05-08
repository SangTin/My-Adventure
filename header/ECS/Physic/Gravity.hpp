#pragma once
#include "../ECS.hpp"
#include "../TransformComponent.hpp"

class Gravity : public Component{
    private:
        TransformComponent* transform;
        double gravitySpeed = 0;
    public:
        void init() override;
        void update() override;
        void on_ground();
};
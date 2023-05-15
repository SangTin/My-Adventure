#pragma once
#include <ECS/Entity/Character.hpp>

class Enemy : public Character{
    private:
        RigidBody* rigidbody;
        ColliderComponent* collider;

        int score;
        double delta_time;

    public:
        void init() override;
        void update() override;
};
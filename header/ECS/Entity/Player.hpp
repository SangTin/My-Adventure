#pragma once
#include "Character.hpp"

class Player : public Character{
    private:
        RigidBody* rigidbody;

    public:
        Player() = default;
        Player(int x, int y, int width, int height, double scale);
        
        void init() override;
        void update() override;
};
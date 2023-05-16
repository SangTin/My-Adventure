#pragma once
#include "Character.hpp"

class Player : public Character{
    private:
        RigidBody* rigidbody;
        KeyboardController* keyboard;
        Sound* sound;
        Vector2D m_Origin;

        double delta_time;
        
        double m_WalkTime;
        double m_JumpTime;
        double m_Jumped;
        
        Vector2D m_lastPosition;
        int health = 3, score = 0;

        double damageTake = 0;
        double deadTime = 0;
        bool isDead = false;
    public:
        ColliderComponent* collider;

        Player() = default;
        Player(int x, int y, int width, int height, double scale);
        
        void init() override;
        void update() override;

        void take_damage();

        Vector2D *get_origin();
        inline int get_health() { return health; }
        inline int get_score() { return score; }
        inline SDL_Rect get_hitbox() { return transform->hitbox; }
        inline bool is_dead() { return isDead; }
};
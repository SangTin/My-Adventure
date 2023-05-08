#pragma once
#include "../ECS.hpp"
#include "../SpriteComponent.hpp"
#include "../Sound.hpp"

class Button : public Component{
    protected:
        TransformComponent* transform;
        SpriteComponent* sprite;
        Sound* sound;

        bool selected, released;
        bool focus, pressed;
        
    public:
        Button() = default;
        void init() override;
        void update() override;
        void lose_focus() override;
        void gain_focus() override;
        void add_sound(const std::string name, const char* path);
        void add_sound(const std::string name, Mix_Chunk* sfx);
        bool is_pressed();
};
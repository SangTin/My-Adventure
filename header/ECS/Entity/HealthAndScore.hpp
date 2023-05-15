#pragma once
#include <ECS/Component/Components.hpp>
#include <Core/FontManager.hpp>
#include <vector>

struct Heart{
    SDL_Texture* texture;
    SDL_Rect src, dst;
    bool isActivated = false;

    Heart() = default;
    Heart(SDL_Texture* texture, SDL_Rect dst);

    void render();
};  

class HealthAndScore : public Entity{
    private:
        TransformComponent *transform;
        SpriteComponent *sprite;

        int health, score;
        std::vector<Heart> hearts;
        SDL_Rect scoreDst;
        std::string scoreText;

    public:
        HealthAndScore(double scale);

        void update() override;
        void render() override;
    private:
        void init_display(double scale);
};
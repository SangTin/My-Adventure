#include <ECS/Entity/HealthAndScore.hpp>
#include <Core/Game.hpp>
#include <State/Play.hpp>
#include <Core/TextureManager.hpp>
#include <charconv> //to_chars
#include <math.h> //log10

#define BOARD_WIDTH 35
#define BOARD_HEIGHT 41
#define HEARTS 3

#define HEART_WIDTH 9
#define HEART_HEIGHT 10


//Start class Heart
Heart::Heart(SDL_Texture *texture, SDL_Rect dst){
    this->texture = texture;
    this->dst = dst;
    this->src = {0, 0, HEART_WIDTH, HEART_HEIGHT};
}

void Heart::render(){
    if (isActivated) src.x = HEART_WIDTH;
    else src.x = 0;
    TextureManager::draw(texture, &src, &dst);
}
//End class Heart

//Start class HealthAndScore
HealthAndScore::HealthAndScore(double scale){
    const int SCREEN_WIDTH = Game::get_screen_width();
    const int BOARD_X = SCREEN_WIDTH - 10 - BOARD_WIDTH * scale;
    const int BOARD_Y = 10;
    transform = &add_component<TransformComponent>(BOARD_X, BOARD_Y, BOARD_WIDTH, BOARD_HEIGHT, scale);
    sprite = &add_component<SpriteComponent>("assets/img/states/Levels/HealthAndScore.png", BOARD_WIDTH, BOARD_HEIGHT);

    init_display(scale);
    health = 0;
    score = 0;
    scoreText = "000";
}

void HealthAndScore::update(){
    health = Play::player->get_health();
    score = Play::player->get_score();
    for (int i = 0; i < HEARTS; ++i){
        hearts[i].isActivated = (i < health);
    }
    int numLen = log10(std::max(score, 1)) + 1;
    std::to_chars(scoreText.data() + scoreText.size() - numLen, scoreText.data() + scoreText.size(), score);
}

void HealthAndScore::render(){
    Entity::render();
    for (int i = 0; i < HEARTS; ++i) hearts[i].render();
    FontManager::draw_text(scoreText, &scoreDst, 15, NULL, {144, 98, 93, 255});
}

void HealthAndScore::init_display(double scale){
    hearts.resize(HEARTS);
    SDL_Rect baseDst = transform->dst;

    int x = baseDst.x + 3 * scale;
    const int y = baseDst.y + 4 * scale;
    const int width = HEART_WIDTH * scale;
    const int height = HEART_HEIGHT * scale;

    SDL_Texture* heartTexture = TextureManager::load_texture("assets/img/states/Levels/Health.png");
    for (int i = 0; i < HEARTS; ++i){
        hearts[i] = Heart(heartTexture, {x, y, width, height});
        x += width + scale * 1;
    }

    scoreDst.x = baseDst.x + 12 * scale;
    scoreDst.y = baseDst.y + 28 * scale;
    scoreDst.w = 17 * scale;
    scoreDst.h = 8 * scale;
}
//End class HealthAndScore
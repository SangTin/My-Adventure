#include <ECS/Entity/Player.hpp>
#include <Core/Files.hpp>
#include <Core/GameTimer.hpp>
#include <Core/HandleEvent.hpp>
#include <Core/Collision.hpp>
#include <Map/GameMap.hpp>

#define JUMP_TIME 40
#define WALK_TIME 60
#define JUMP_FORCE (rigidbody->cal_jumpForce())
#define RUN_FORCE 3
#define WALK_FORCE (RUN_FORCE * 2 / 3)
#define DAMAGE_TIME 20
#define DEAD_TIME 150

Player::Player(int x, int y, int width, int height, double scale){
    transform = &add_component<TransformComponent>(x, y, width, height, scale);
    animation = &add_component<AnimationComponent>(width, height, true);

    m_Origin = Vector2D(x + transform->dst.w / 2.0, y + transform->dst.h / 2.0);
    health = 3;
    score = 0;
}

void Player::init(){
    collider = &add_component<ColliderComponent>("Player");
    rigidbody = &add_component<RigidBody>();
    keyboard = &add_component<KeyboardController>();
    sound = &add_component<Sound>();
    add_group(Base::groupPlayers);

    transform->add_hitbox(6, 0, 10, 11);

    vector <string> animationList = Files::get_files_list("assets/img/player");
    for (string &path : animationList){
        string name = Files::split_filename(path);
        animation->add_animation(name, path.c_str());
    }
    play_action("Idle", 200);

    sound->add_sound("Jump", "assets/sound/playing/Jump.mp3");
    sound->add_sound("Dead", "assets/sound/playing/Dead.mp3");
    sound->add_sound("Hit", "assets/sound/playing/Hit.mp3");
}

void Player::update(){
    delta_time = GameTimer::get_DT();
    if (damageTake > 0) damageTake += delta_time;
    if (damageTake >= DAMAGE_TIME) damageTake = 0;
    action = false;
    Character::update();
    Vector2D keyboardForce = keyboard->get_direction();

    rigidbody->stop_force();
    
    if (deadTime > 0){
        play_action("Dead", 200);
        deadTime += delta_time;
        if (deadTime >= DEAD_TIME){
            isDead = true;
        }
        rigidbody->update(delta_time);
        return;
    }

    if (keyboardForce.x != 0){
        m_WalkTime -= delta_time;
        if (rigidbody->is_grounded()){
            if (m_WalkTime > 0){
                play_action("Walk", 250);
                rigidbody->apply_forceX(WALK_FORCE * keyboardForce.x);
            }
            else{
                play_action("Run", 150);
                rigidbody->apply_forceX(RUN_FORCE * keyboardForce.x);
            }
        }
        else {
            rigidbody->apply_forceX(RUN_FORCE * keyboardForce.x);
        }
        action = true;
        animation->flip = (keyboardForce.x > 0 ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL);
    }

    if (keyboardForce.y < 0 && !m_Jumped){
        m_Jumped = true;
        m_JumpTime = JUMP_TIME;
        sound->play_sound("Jump");
    }
    if (m_Jumped && m_JumpTime > 0){
        play_action("Jumping", 150);
        m_JumpTime -= delta_time;
        rigidbody->apply_forceY(-JUMP_FORCE);
    }
    rigidbody->update(delta_time);

    if (rigidbody->get_map_collision().y){
        m_JumpTime = 0;
        if (rigidbody->is_grounded()){
            m_Jumped = false;
        }
    }
    if (rigidbody->get_position().y > 0 && !rigidbody->is_grounded()){
        if (rigidbody->get_map_collision().x){
            play_action("WallFall", 150);
            rigidbody->set_gravity(GRAVITY / 2);
            animation->flip = (keyboardForce.x > 0 ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
            m_Jumped = false;
        }
        else{
            play_action("Falling", 150);
            rigidbody->set_gravity(GRAVITY);
        }
    }
    
    if (!action && rigidbody->is_grounded()){
        play_action("Idle", 200);
        m_WalkTime = WALK_TIME;
    }
    if (damageTake > 0){
        play_action("Hit", 150);
    }
    if (!health && deadTime == 0){
        deadTime += delta_time;
        sound->play_sound("Dead");
    }
    m_Origin.x = transform->dst.x + transform->dst.w / 2.0;
    m_Origin.y = transform->dst.y + transform->dst.h / 2.0;
}

Vector2D *Player::get_origin(){
    return &m_Origin;
}

void Player::take_damage(){
    if (!health || damageTake > 0) return;
    sound->play_sound("Hit");
    damageTake += delta_time;
    --health;
    m_Jumped = true;
    m_JumpTime = JUMP_TIME;
}
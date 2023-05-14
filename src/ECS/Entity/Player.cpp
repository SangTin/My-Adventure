#include <ECS/Entity/Player.hpp>
#include <Core/Files.hpp>
#include <Core/GameTimer.hpp>

Player::Player(int x, int y, int width, int height, double scale){
    transform = &add_component<TransformComponent>(x, y, width, height, scale);
    animation = &add_component<AnimationComponent>(width, height);
}

void Player::init(){
    rigidbody = &add_component<RigidBody>();
    add_component<KeyboardController>();
    add_group(Base::groupPlayers);

    vector <string> animationList = Files::get_files_list("assets/img/player");
    for (string &path : animationList){
        string name = Files::split_filename(path);
        animation->add_animation(name, path.c_str(), 150);
    }
    play_action("Idle");
}

void Player::update(){
    Character::update();
    rigidbody->update(0.5);
    transform->move(rigidbody->get_position());
}
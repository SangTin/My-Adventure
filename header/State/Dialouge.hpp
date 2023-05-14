#pragma once
#include "States.hpp"
#include <State/Dialouge.hpp>
#include <Core/HandleEvent.hpp>
#include <Core/FontManager.hpp>
#include <UI/Mouse.hpp>
    
#define SCALE 3
#define BG_WIDTH 170
#define BG_HEIGHT 60

#define BUTTON_WIDTH 20
#define BUTTON_HEIGHT 22

#define TEXTBOX_X 64
#define TEXTBOX_Y 23
#define TEXTBOX_WIDTH 93
#define TEXTBOX_HEIGHT 21

template <typename T>
class Dialouge : public GameState{
    private:
        Entity *dialog;
        TransformComponent* transform;
        ClickedButton *Yes, *No;
        Character* Cat;
        std::string message;
        bool activated = false;

    public:
        Dialouge(const char* message){
            this->message = message;
        }

        void init() override{
            dialog = &manager.add_entity<Entity>();
            transform = &dialog->add_component<TransformComponent>(0, -(BUTTON_HEIGHT * SCALE) / 2, BG_WIDTH, BG_HEIGHT, SCALE);
            transform->centered();
            dialog->add_component<SpriteComponent>("assets/img/states/Dialouge/Dialog.png", BG_WIDTH, BG_HEIGHT);
            
            //Add yes-no buttons
            const int BUTTON_Y = transform->dst.y + transform->dst.h;
            const int YES_X = transform->dst.x + transform->dst.w - (BUTTON_WIDTH * SCALE) * 2;
            const int NO_X = transform->dst.x + (BUTTON_WIDTH * SCALE);
            Yes = &manager.add_entity<ClickedButton>("assets/img/button/VButton.png", YES_X, BUTTON_Y, BUTTON_WIDTH, BUTTON_HEIGHT, SCALE);
            No = &manager.add_entity<ClickedButton>("assets/img/button/XButton.png", NO_X, BUTTON_Y, BUTTON_WIDTH, BUTTON_HEIGHT, SCALE);

            //Add sound to buttons
            for (auto& b : manager.get_group(Base::groupButtons)){
                b->add_sound("Hover", "assets/sound/menu/MenuHover.mp3");
                b->add_sound("Pressed", "assets/sound/menu/MenuPressed.mp3");
            }

            //Add a cute cate :3
            const int CAT_X = transform->dst.x + 13 * SCALE;
            const int CAT_Y = transform->dst.y + 13 * SCALE;
            Cat = &manager.add_entity<Character>(CAT_X, CAT_Y, 32, 32, 3);
            Cat->add_action("Idle", "assets/img/states/Dialouge/CatCharacter.png", 200);
            Cat->play_action("Idle");
        }

        void update() override{
            GameState::update();

            if (HandleEvent::get_key_down(SDL_SCANCODE_ESCAPE) || No->is_pressed()){
                destroy();
            }
            if (HandleEvent::get_key_down(SDL_SCANCODE_RETURN) || Yes->is_pressed()){
                StateManager::add_state<T>();
                activated = true;
            }
        }

        void render() override{
            GameState::render();

            const int textX = transform->dst.x + TEXTBOX_X * SCALE;
            const int textY = transform->dst.y + TEXTBOX_Y * SCALE;
            SDL_Rect textDst = {textX, textY, TEXTBOX_WIDTH * SCALE, TEXTBOX_HEIGHT * SCALE};
            FontManager::draw_text(message, &textDst, 15, NULL, {107, 75, 91, 255});
        }

        inline bool is_activated(){
            return activated;
        }
};

#undef SCALE
#undef BG_WIDTH
#undef BG_HEIGHT
#undef BUTTON_WIDTH
#undef BUTTON_HEIGHT
#undef TEXTBOX_X
#undef TEXTBOX_Y
#undef TEXTBOX_WIDTH 
#undef TEXTBOX_HEIGHT 
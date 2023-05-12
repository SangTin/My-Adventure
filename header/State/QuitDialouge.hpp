#pragma once
#include "GameState.hpp"

class QuitDialouge : public GameState{
    private:
        Entity *dialog;
        TransformComponent* transform;
        ClickedButton *Yes, *No;
        Character* Cat;
    
    public:
        void init() override;
        void update() override;
        void render() override;
};
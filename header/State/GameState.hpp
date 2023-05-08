#pragma once
#include <vector>
#include <ECS/Components.hpp>

class GameState{
    protected:
        bool active = true;
        bool hidden = false;
        EnityManager manager;

    public:
        virtual ~GameState(){}

        //Get called when the state first get set
        virtual void init() = 0;
        virtual void refresh();
        virtual void update();
        virtual void render();
        virtual void lose_focus();
        virtual void gain_focus();
        virtual void hide();
        virtual void show();

        bool is_active() const;
        void destroy();
};
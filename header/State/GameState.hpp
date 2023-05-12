#pragma once
#include <vector>
#include <ECS/Component/Components.hpp>
#include <ECS/Entity/Entities.hpp>

class GameState{
    protected:
        bool active = true;
        bool hidden = false;
        EntityManager manager;

    public:
        virtual ~GameState(){}

        //Get called when the state first get set
        virtual void init() = 0;
        virtual void refresh();
        virtual void update();
        virtual void render();
        virtual void hide();
        virtual void show();
        virtual void destroy();

        bool is_active() const;
};
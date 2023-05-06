#pragma once
#include <vector>
#include <ECS/ECS.hpp>

class GameState{
    protected:
        bool active = true;
        EnityManager manager;

    public:
        virtual ~GameState() = 0;

        //Get called when the state first get set
        virtual void init() = 0;
        void refresh();
        void update();
        void render();

        bool is_active() const;
        void destroy();
};
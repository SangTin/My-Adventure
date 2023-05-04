#pragma once
#include <vector>

class GameState{
    protected:
        bool active;
    public:
        virtual ~GameState() = 0;

        //Get called when the state first get set
        virtual void init() = 0;

        virtual void update() = 0;
        virtual void render() = 0;
        virtual bool is_active();
        virtual void destroy();
};
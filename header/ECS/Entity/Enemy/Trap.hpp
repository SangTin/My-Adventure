#pragma once
#include <ECS/Entity/Tile.hpp>

class Trap : public Tile{
    public:
        void init() override;
        void update() override;
};
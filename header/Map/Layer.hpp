#pragma once
#include <Tileson/tileson.hpp>
#include <vector>

class Layer{
    private:
        std::vector <uint32_t> data;
        int numRows, numCols;
        int x, y;
    public:
        Layer(tson::Layer layer);
        void render();
};
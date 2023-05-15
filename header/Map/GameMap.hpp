#pragma once
#include <Tileson/tileson.hpp>
#include <ECS/ECS.hpp>
#include <SDL2/SDL.h>
#include <vector>
#include <map>
#include <string>

#define TILE_SCALE 3

class GameMap{
    private:
        int tileCols, tileRows;
        static int mapWidth, mapHeight;

        std::map<std::string, SDL_Texture*> tilesetTextures;

        std::vector<tson::Layer> layers;
        tson::Layer *spawnPoints;

    public:
        std::unique_ptr<tson::Map> map;
        static EntityManager *manager;

        static int get_map_width();
        static int get_map_height();

        void init(const std::string);
        void update();
        void render();
        
        SDL_Point get_player_spawn();
    private:
        void load_layer_data(std::string);
};
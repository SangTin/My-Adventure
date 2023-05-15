#include <Map/GameMap.hpp>
#include <Core/TextureManager.hpp>
#include <ECS/Entity/Entities.hpp>
#include <Core/Base.hpp>

EntityManager* GameMap::manager;

int GameMap::mapWidth;
int GameMap::mapHeight;

int GameMap::get_map_width(){
    return mapWidth;
}

int GameMap::get_map_height(){
    return mapHeight;
}

void GameMap::init(const std::string source){
    manager = new EntityManager();
    tson::Tileson file;
    map = file.parse(fs::path(source));
    tileCols = map->getSize().x;
    tileRows = map->getSize().y;

    mapWidth = tileCols * baseSquare * TILE_SCALE;
    mapHeight = tileRows * baseSquare * TILE_SCALE;

    layers = map->getLayers();
    for (auto& layer : layers){
        if (layer.getType() == tson::LayerType::ObjectGroup){
            spawnPoints = &layer;
        }
        else{
            load_layer_data(layer.getName());
        }
    }
}

void GameMap::update(){
    manager->update();
}

void GameMap::render(){
    manager->render();
}

SDL_Point GameMap::get_player_spawn(){
    if (!spawnPoints) return {0, 0};
    tson::Object* player = spawnPoints->firstObj("PlayerSpawn");
    return {player->getPosition().x, player->getPosition().y};
}

void GameMap::load_layer_data(std::string name){
    std::vector<uint32_t> data = map->getLayer(name)->getData();

    for (int r = 0; r < tileRows; ++r){
        for (int c = 0; c < tileCols; ++c){
            int cur_tile = (r * tileCols) + c;
            if (!data[cur_tile]) continue;

            tson::Tileset *tileset = map->getTilesetByGid(data[cur_tile]);
            if (tilesetTextures.find(tileset->getName()) == tilesetTextures.end()){
                tilesetTextures[tileset->getName()] = TextureManager::load_texture(tileset->getImagePath().string());
            }

            const int x = c * baseSquare * TILE_SCALE;
            const int y = r * baseSquare * TILE_SCALE;
            tson::Tile *tile = tileset->getTile(data[cur_tile]);
            tson::Rect tileRect = tile->getDrawingRect();
            SDL_Rect tileSrc = {tileRect.x, tileRect.y, tileRect.width, tileRect.height};
            SDL_Texture* texture = tilesetTextures[tileset->getName()];
            Tile *tileEntity;
            if (name == "Traps"){
                tileEntity = &manager->add_entity<Trap>();
            }
            else{
                tileEntity = &manager->add_entity<Tile>();
            }
            tileEntity->init(texture, x, y, tileSrc, cur_tile, TILE_SCALE);
            if (name == "Platform"){
                tileEntity->add_map_collider();
            }
        }
    }
}


void Player::take_damage(){
    --health;
}
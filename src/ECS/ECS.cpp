#include <ECS/ECS.hpp>

//Start class Entity
void Entity::update(){
    for (auto &c : components) c->update();
}

void Entity::render(){
    for (auto &c : components) c->render();
}

void Entity::refresh(){
    for (auto &c : components) c->refresh();
}

bool Entity::is_active() const{ 
    return active; 
}

void Entity::destroy() { 
    active = false; 
}

bool Entity::has_group(Group oGroup){
    return groupBitSet[oGroup];
}

void Entity::add_group(Group oGroup){
    groupBitSet[oGroup] = true;
}

void Entity::del_group(Group oGroup){
    groupBitSet[oGroup] = false;
}

Entity* Entity::get_entity(){
    return this;
}
//End class Entity

//Start class EnityManager
void EnityManager::update(){
    for (auto &e : entities) e->update();
}
void EnityManager::render(){
    for (auto &e : entities) e->render();
}
void EnityManager::refresh(){
    for (auto i(0u); i < maxGroups; ++i){
        auto& v(groupedEntities[i]);
        v.erase(std::remove_if(std::begin(v), std::end(v),
            [i](Entity* mEntity)
        {
            return !mEntity->is_active() || !mEntity->has_group(i);
        }),
            std::end(v));
    }

    entities.erase(std::remove_if(std::begin(entities), std::end(entities), 
        [](std::unique_ptr<Entity> &mEntity)
    {
        if (mEntity->is_active()) return false;
        mEntity.reset();
        return true;
    }),
        std::end(entities));

    for (auto &e : entities) e->refresh();
}

void EnityManager::add_to_group(Entity* mEntity, Group mGroup){
    groupedEntities[mGroup].emplace_back(mEntity);
}

std::vector<Entity*>& EnityManager::get_group(Group mGroup){
    return groupedEntities[mGroup];
}

Entity& EnityManager::add_entity(){
    Entity* e = new Entity(*this);
    std::unique_ptr<Entity> uPtr{ e };
    entities.emplace_back(std::move(uPtr));
    return *e;  
}
//End class EnityManager
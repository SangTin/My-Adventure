#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;
class EnityManager;

using ComponentID = std::size_t;
using Group = std::size_t;

inline ComponentID get_new_component_ID(){
    static ComponentID lastComponentID = 0;
    return lastComponentID++;
}

template <typename T> inline ComponentID get_component_ID() noexcept{
    static_assert (std::is_base_of<Component, T>::value, "");
    static ComponentID typeID = get_new_component_ID();
    return typeID;
}

constexpr std::size_t maxComponents = 32;
constexpr std::size_t maxGroups = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using GroupBitSet = std::bitset<maxGroups>;

using ComponentArray = std::array<Component*, maxComponents>;

class Component{
    public:
        Entity* entity;

        virtual void init(){}
        virtual void update(){}
        virtual void render(){}
        virtual void refresh(){}

        virtual ~Component(){}
};

class Entity{
    private:
        EnityManager& manager;
        bool active = true;
        std::vector<std::unique_ptr<Component>> components;

        ComponentArray componentArray;
        ComponentBitSet componentBitSet;
        GroupBitSet groupBitSet;
    public:
        Entity(EnityManager& oManager) : manager(oManager){}

        void update();
        void render();
        void refresh();
        bool is_active() const;
        void destroy();
        bool has_group(Group oGroup);
        void add_group(Group oGroup);
        void del_group(Group oGroup);

        template <typename T> bool has_component()const{
            return componentBitSet[get_component_ID<T>()];
        }

        template <typename T, typename... TArgs> T& add_component(TArgs&&... mArgs){
            T* c(new T(std::forward<TArgs>(mArgs)...));
            c->entity = this;
            std::unique_ptr<Component> uPtr{ c };
            components.emplace_back(std::move(uPtr));

            componentArray[get_component_ID<T>()] = c;
            componentBitSet[get_component_ID<T>()] = true;

            c->init();
            return *c;
        }

        template<typename T> T& get_component() const{
            auto ptr(componentArray[get_component_ID<T>()]);
            return *static_cast<T*>(ptr);
        }
};  

class EnityManager{
    private:
        std::vector<std::unique_ptr<Entity>> entities;
        std::array<std::vector<Entity*>, maxGroups> groupedEntities;

    public:
        void update();
        void render();
        void refresh();
        void add_to_group(Entity* mEntity, Group mGroup);
        std::vector<Entity*>& get_group(Group mGroup);
        Entity& add_entity();
};
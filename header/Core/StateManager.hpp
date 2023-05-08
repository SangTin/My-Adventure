#pragma once
#include <vector>
#include <array>
#include <bitset>
#include <memory>
#include <State/GameState.hpp>

using StateID = std::size_t;

inline StateID get_new_state_ID(){
    static StateID lastStateID = 0;
    return lastStateID++;
}

template <typename T> inline StateID get_state_ID() noexcept{
    static_assert (std::is_base_of<GameState, T>::value, "");
    static StateID typeID = get_new_state_ID();
    return typeID;
}

constexpr std::size_t maxStates = 32;
#include <iostream>
class StateManager{
    private:
        static std::vector<std::unique_ptr<GameState>> states;
    public:
        static void refresh();
        static void update();
        static void render();
        static void clear();

        template <typename T, typename... TArgs> static T& add_state(){
            T* s(new T);
            std::unique_ptr<GameState> uPtr{ s };
            states.emplace_back(std::move(uPtr));

            s->init();
            return *s;
        }
};
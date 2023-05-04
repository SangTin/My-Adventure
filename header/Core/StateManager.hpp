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

using StateBitSet = std::bitset<maxStates>;
using StateArray = std::array<GameState*, maxStates>;

class StateManager{
    private:
        static std::vector<std::unique_ptr<GameState>> states;
        static StateArray stateArray;
    public:
        static void init();
        static void refresh();
        static void update();
        static void render();

        template <typename T> bool has_state()const{
            return (stateArray[get_state_ID<T>()] != nullptr);
        }

        template <typename T, typename... TArgs> static T& add_state(){
            T* c(new T);
            std::unique_ptr<GameState> uPtr{ c };
            states.emplace_back(std::move(uPtr));
            stateArray[get_state_ID<T>()] = uPtr;
            return *c;
        }

        template<typename T> static T& get_state(){
            if (!has_state<T>()) add_state<T>();

            auto ptr(stateArray[get_state_ID<T>()]);
            return *static_cast<T*>(ptr);
        }
};
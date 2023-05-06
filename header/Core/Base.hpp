#pragma once
#include <cstddef> //size_t
#include <SDL2/SDL.h>

#define baseSquare 32

namespace Base{
    enum groupLabels : std::size_t{
        groupMap,
        groupPlayers,
        groupEnemies,
        groupColliders
    };

    enum mouseStats : std::size_t{
        mousePointing,
        mouseHolding,
        mouseIdle
    };

    enum buttonNames : std::size_t{
        playButton,
        settingButton,
        quitButton
    };

    enum mouseButtonNames : std::size_t{
        leftMouse,
        middleMouse,
        rightMouse,
        x1Mouse,
        x2Mouse
    };

    const SDL_Color defaultColor = {196, 154, 108, 255};
}
#pragma once
#include <cstddef> //size_t
#include <SDL2/SDL.h>

#define baseSquare 16

namespace Base{
    enum groupLabels : std::size_t{
        groupMap,
        groupColliders,
        groupEnemies,
        groupPlayers,
        groupButtons,
        groupNan
    };

    enum mouseStats : std::size_t{
        mousePointingHolding,
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

    enum sliderType{
        sfxID = 16,
        musicID = 9,
        sliderNan = -1
    };

    const SDL_Color defaultColor = {196, 154, 108, 255};
}
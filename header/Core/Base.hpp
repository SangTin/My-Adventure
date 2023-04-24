#pragma once
#include <cstddef> //size_t

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
        mouseIdle,
        mouseNan
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
}
#pragma once
#include "Button.hpp"

class ClickedButton : public Button{
    public:
        ClickedButton() = default;
        void update() override;
};
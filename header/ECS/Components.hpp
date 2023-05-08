#pragma once
#include "ECS.hpp"
#include "TransformComponent.hpp"
#include "SpriteComponent.hpp"
#include "KeyboardController.hpp"
#include "Button/Button.hpp"
#include "Button/ClickedButton.hpp"
#include "Sound.hpp"
#include "Physic/Gravity.hpp"

namespace Components{
    ClickedButton& create_clicked_button(EnityManager& manager, const char* path, int x, int y, int width, int height, double scale, bool centered = false);
}
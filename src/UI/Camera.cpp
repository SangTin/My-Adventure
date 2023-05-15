#include <UI/Camera.hpp>
#include <Map/GameMap.hpp>
#include <Core/Game.hpp>

Vector2D Camera::m_Position;
Vector2D* Camera::m_Target = nullptr;
SDL_Rect Camera::m_Viewbox;
SDL_Rect Camera::m_UpdateArea;

#define IN(a, b, c) (a <= b && b <= c)

void Camera::update(){
    const int MAP_WIDTH = GameMap::get_map_width();
    const int MAP_HEIGHT = GameMap::get_map_height();
    
    if (m_Target != nullptr){
        if (!IN(m_UpdateArea.x, m_Target->x, m_UpdateArea.x + m_UpdateArea.w)){
            if (m_Target->x > m_UpdateArea.x) m_UpdateArea.x = (m_Target->x - m_UpdateArea.w);
            else m_UpdateArea.x = m_Target->x;
        }
        if (!IN(m_UpdateArea.y, m_Target->y, m_UpdateArea.y + m_UpdateArea.h)){
            if (m_Target->y > m_UpdateArea.y) m_UpdateArea.y = (m_Target->y - m_UpdateArea.h);
            else m_UpdateArea.y = m_Target->y;
        }

        m_Viewbox.x = m_UpdateArea.x - m_Viewbox.w / 3;
        m_Viewbox.y = m_UpdateArea.y - m_Viewbox.h / 3;
        
        if ((m_Viewbox.x + m_Viewbox.w) > MAP_WIDTH){
            m_Viewbox.x = (MAP_WIDTH - m_Viewbox.w);
        }
        if ((m_Viewbox.y + m_Viewbox.h) > MAP_HEIGHT){
            m_Viewbox.y = (MAP_HEIGHT - m_Viewbox.h);
        }
        
        if (m_Viewbox.x < 0) m_Viewbox.x = 0;
        if (m_Viewbox.y < 0) m_Viewbox.y = 0;

        m_Position = Vector2D(m_Viewbox.x, m_Viewbox.y);
    }
}

void Camera::set_target(Vector2D *target){
    m_Target = target;
    if (!target) return;
    const int SCREEN_WIDTH = Game::get_screen_width();
    const int SCREEN_HEIGHT = Game::get_screen_height();
    m_Viewbox = {(int)target->x - SCREEN_WIDTH / 2, (int)target->y - SCREEN_HEIGHT / 3, SCREEN_WIDTH, SCREEN_HEIGHT};
    m_UpdateArea.x = m_Viewbox.x + m_Viewbox.w / 3;
    m_UpdateArea.y = m_Viewbox.y + m_Viewbox.h / 3;
    m_UpdateArea.w = m_Viewbox.w - 2 * m_Viewbox.w / 3;
    m_UpdateArea.h = m_Viewbox.h - 2 * m_Viewbox.h / 3;
    m_Position = Vector2D(0, 0);
}

SDL_Rect Camera::get_viewbox(){
    return m_Viewbox;
}

Vector2D Camera::get_position(){
    return m_Position;
}
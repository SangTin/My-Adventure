#pragma once

class GameTimer{
    private:
        static unsigned int m_OldTick;
        static unsigned int m_CurrentTick;

        friend class StateManager;
        static void update_timer();
    public:
        static double get_DT();
};
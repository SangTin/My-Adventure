#pragma once

class GameTimer{
    private:
        static double m_DeltaTime, m_OldTime;

    public:
        static void update_timer();
        
        static inline double get_DT(){
            return m_DeltaTime;
        }
};
#pragma once

#define EXTRAS 1
#define DECIMAL double
#define DRIVE_SPEED_GAIN 1.0


void helpMe(DECIMAL a);

#if EXTRAS


// put extra code here

#else

// put not extra code here

#endif


enum IntakeState {
    INIT,
    IN,
    OUT,
    IDLE,
    E_STOP
};

struct InputValues {
    bool in_button, out_button, stop_button, reset_button, estop;
};

class Intake {
private:
    IntakeState m_State = IntakeState::INIT;
    IntakeState m_LastState = IntakeState::IDLE;
public:

    Intake();

    inline IntakeState getState() { return m_State; };
    inline IntakeState getLastState() { return m_LastState; };

    inline void setState(IntakeState state) { m_State = state; };

    void stateMachine(InputValues const values);
    
    const void in();
    const void out();
    const void idle();
    const void reinit();
    const void emergency();
};

#include "project_main.hpp"

#include <iostream>

void helpMe(DECIMAL a) {
    std::cout << a << " " << DRIVE_SPEED_GAIN;
}

Intake::Intake() {

}

void Intake::stateMachine(InputValues const values) {
    m_LastState = m_State;
    if (values.estop) {
        setState(IntakeState::E_STOP);
    } else if (values.reset_button) {
        setState(IntakeState::INIT);
    } else if (values.stop_button) {
        setState(IntakeState::IDLE);
    } else if (values.in_button) {
        setState(IntakeState::IN);
    } else if (values.out_button) {
        setState(IntakeState::OUT);
    }

    if (m_State == m_LastState) return; 

    switch (getState()) {
    case IntakeState::INIT:
        reinit();
        break;
    case IntakeState::IN:
        in();
        break;
    case IntakeState::OUT:
        out();
        break;
    case IntakeState::IDLE:
        idle();
        break;
    case IntakeState::E_STOP:
        emergency();
        break;
    }
}

const void Intake::in() {
    std::cout << "Intake State -> IN\n";
}

const void Intake::out() {
    std::cout << "Intake State -> OUT\n";
}

const void Intake::idle() {
    std::cout << "Intake State -> IDLE\n";
}

const void Intake::reinit() {
    std::cout << "Intake State -> (RE)INIT\n";
    setState(IntakeState::IDLE);
}

const void Intake::emergency() {
    std::cout << "Intake State -> E_STOP\n";
}

int main() {

    helpMe(4.0);

    Intake* intake = new Intake();

    InputValues input{false,false,false,false,false};

    int updates = 0;

    while (intake->getState() != IntakeState::E_STOP) {
        updates++;

        if (updates == 100) {
            input.in_button = true;
        } else if (updates == 200) {
            input.in_button = false;
            input.stop_button = true;
        } else if (updates == 300) {
            input.stop_button = false;
            input.reset_button = true;
        } else if (updates == 400) {
            input.reset_button = false;
            input.out_button = true;
        } else if (updates == 500) {
            input.out_button = false;
            input.estop = true;
        }

        if (input.reset_button && intake->getState() == IntakeState::INIT   ) {
            input.reset_button = false;
        }

        intake->stateMachine(input);
    }
    
}
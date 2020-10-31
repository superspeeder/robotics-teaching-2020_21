#include <iostream>
#include <string>

enum ClawState {
    OPEN = 0,
    CLOSED = 1,
    INIT = 2,
    OFF = 3
};

class Claw {
private:
    std::string m_Name;
    ClawState m_ClawState;
public:

    Claw(std::string name);

    inline void setState(ClawState newState) { m_ClawState = newState; };
    inline ClawState getState() { return m_ClawState; };

    void runStateMachine();

    void open();
    void close();
    void off();
    void init();
};


Claw::Claw(std::string name) : m_Name(name), m_ClawState(ClawState::INIT) { }

void Claw::runStateMachine() {
    switch (m_ClawState) {
    case ClawState::OPEN:
        open();
        break;
    case ClawState::CLOSED:
        close();
        break;
    case ClawState::OFF:
        off();
        break;
    case ClawState::INIT:
        init();
        break;
    }
}

void Claw::open() {
    std::cout << "Claw " << m_Name << " is opening\n";
}

void Claw::close() {
    std::cout << "Claw " << m_Name << " is closing\n";
}

void Claw::off() {
    std::cout << "Claw " << m_Name << " is shutting off\n";
}

void Claw::init() {
    std::cout << "Claw " << m_Name << " is initialized\n";    
}

int main() {

    std::string clawName;

    std::cout << "What is the name of the claw (no spaces)? ";
    std::cin >> clawName;

    std::cout << "Available States:\n\t[0] Open\n\t[1] Closed\n\t[2] Re-Init\n\t[3] Off\n";

    int input_intermediate;

    Claw* claw = new Claw(clawName);

    while (claw->getState() != ClawState::OFF) {

        std::cout << "Pick a state: ";
        std::cin >> input_intermediate;

        claw->setState(static_cast<ClawState>(input_intermediate));
        claw->runStateMachine();

    }

    std::cout << "Claw Simulation Complete\n";
}
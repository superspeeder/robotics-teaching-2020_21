#include <iostream>
#include <string>


enum ClawState {
    OPEN = 0,
    CLOSED = 1,
    OFF = 2
};

void open(std::string name) {
    std::cout << "Claw " << name << " is opening\n";
}

void close(std::string name) {
    std::cout << "Claw " << name << " is closing\n";
}

void off(std::string name) {
    std::cout << "Claw " << name << " is shutting off\n";
}

int main() {

    std::string clawName;

    std::cout << "What is the name of the claw (no spaces)? ";
    std::cin >> clawName;

    ClawState state = ClawState::OPEN;
    std::cout << "Available States:\n\t[0] Open\n\t[1] Closed\n\t[2] Off\n";

    int i;

    while (state != ClawState::OFF) {
        std::cout << "Pick a state: ";
        std::cin >> i;
    
        state = static_cast<ClawState>(i);
    
        switch (state) {
        case ClawState::OPEN:
            open(clawName);
            break;
        case ClawState::CLOSED:
            close(clawName);
            break;
        }
    }
    off(clawName);
    return 0;
}
#include <iostream>

enum State {
    OPEN = 0,
    CLOSE = 1,
    END = 2
};

void open() {
    std::cout << "Opening Claw" << std::endl;
}

void close() {
    std::cout << "Closing Claw" << std::endl;
}


int main() {
    State input = State::OPEN;
    int intermediate;
    std::cout << "States:\n\t[0] OPEN\n\t[1] CLOSE\n\t[2] END\n";

    while (input != State::END) {
        std::cout << "Please enter the next state: ";
        std::cin >> intermediate;
        input = static_cast<State>(intermediate);
        switch(input) {
        case State::CLOSE:
            close();
            break;
        case State::OPEN:
            open();
            break;
        }
    }

    std::cout << "Simulation Complete\n";

    return 0;
}
#include <iostream>

#include "Main.hpp"

void print(const char* string, size_t size) {
    for (size_t i = 0 ; i < size ; i++) {
        std::cout << string[i];
    }
}

void println(const char* string, size_t size) {
    print(string, size);
    std::cout << std::endl;
}

std::string Arm::getDebugName() {
    return "<Arm {motor: " + std::to_string(this->getMotorID()) + "} >";
}

Robot::Robot(unsigned int motor1Id, unsigned int motor2Id) {
    m_Arm = new Arm(motor1Id);
    m_Arm2 = new Arm(motor2Id);
}

std::string Robot::getDebugName() {
    return "<Robot " + std::to_string(TeamNumber) + ">";
}

void Robot::printDebugInfo() {
    std::string r_str = getDebugName();
    println_macro(r_str);

    std::string a1_str = getArm1()->getDebugName();
    std::string a2_str = getArm2()->getDebugName();

    println_indent_macro(a1_str);
    println_indent_macro(a2_str);
}

Robot::~Robot() {
    delete m_Arm, m_Arm2;
    println_macro("Destroyed Arms");
}

int main() {

    std::cout << "help\n";

    println(new char[4] {'h','e','l','p'}, 4);

    Robot *robot = new Robot(0, 10);

    robot->printDebugInfo();

    int a = 29;

    int* a_addr = &a;

    int b = *a_addr;

    println_macro(a << " " << a_addr << " " << b);
    // std::cout << a << " " << a_addr << " " << b;

    delete robot;

    return 0;
}
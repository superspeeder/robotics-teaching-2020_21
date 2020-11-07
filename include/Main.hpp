#pragma once

#include <string>
#include <iostream>

#define print_macro(Value) std::cout << Value
#define println_macro(Value) std::cout << Value << std::endl
#define println_indent_macro(string) print_macro("\t"); println_macro(string)

#define TeamNumber 668

class Arm;

class Robot {
private:
    Arm *m_Arm, *m_Arm2;

public:
    Robot(unsigned int motor1Id, unsigned int motor2Id);
    ~Robot();

    std::string getDebugName();

    void printDebugInfo();

    inline Arm* getArm1() { return m_Arm; };
    inline Arm* getArm2() { return m_Arm2; };
};

class Arm {
private:
    unsigned int m_MotorID;
public:

    Arm(unsigned int motorId) : m_MotorID(motorId) { }

    std::string getDebugName();

    inline unsigned int getMotorID() { return m_MotorID; };
};


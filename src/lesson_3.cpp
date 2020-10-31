#include <iostream>
#include <string>

int main() {
    std::string name;

    std::cout << "Please Enter Your Name: ";
    std::cin >> name;
    std::cout << "Nice to meet you " << name << "!" << std::endl;

    return 0;
}
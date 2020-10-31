#include <iostream>
#include <string>


int main() {

    std::cout << "Hello, World\n";
    
    int aNumber = 2;
    std::cout << "A number is " << aNumber << std::endl;

    std::cout << "Enter A new number: ";
    std::cin >> aNumber;

    std::cout << "Now a number is " << aNumber << std::endl;

    std::string name;

    std::cout << "What is your name? ";
    std::cin >> name;

    std::cout << "Nice to meet you " << name << "!\n";

    

    return 0;
}
#include <iostream>
#include <fstream>
#include "auth.h"


int main() {
    int choice;
    while (true) {
        std::cout << "--------------- MENU ----------------" << std::endl;
        std::cout << "(Choose a number to continue)" << std::endl;
        std::cout << "1- Register new user" << std::endl;
        std::cout << "2- Login" << std::endl;
        std::cout << "0- Exit" << std::endl;
        std::cout << "--------------- EndOfMenu ----------------" << std::endl;
        std::cin >> choice;
        switch (choice) {
            case 1: {
                registerFunction();
                break;
            }
            case 2: {
                loginFunction();
                break;
            }
            case 0: {
                exit(0);
            }
            default:
                std::cout << "Invalid choice\n";
        }
    }

}
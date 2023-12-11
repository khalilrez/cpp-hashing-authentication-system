#include "auth.h"
#include <iostream>
#include <fstream>

unsigned long djb2Hash(const char *str) {
    unsigned long hash = 5381; // could be any number, hedha li 5tarou li sna3 l'algorithme
    int c;

    while ((c = *str++)) { // iterate until c is null ( \0 )
        hash = ((hash << 5) + hash) + c; // hash * 33 + c ( djb2 Hashing Algorithm )
    }

    return hash;
}

bool checkIfUsernameExists(const std::string &username) {
    std::ifstream authFile("passwd.txt");
    if (authFile.is_open()) {
        std::cout << "Checking if username exists... " << std::endl;

        // Read and check usernames
        std::string line;
        while (std::getline(authFile, line)) {
            std::string existingUser = line.substr(0, line.find(';'));
            if (username == existingUser) {
                std::cout << "Username already exists... exiting to menu \n";
                return false;
            }
        }

        authFile.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }
    return true;
}

void saveToPasswdFile(const std::string &username, const std::string &password) {
    unsigned long hashValue = djb2Hash(password.c_str());
    std::ofstream authFile("passwd.txt", std::ios::out | std::ios::app);

    if (authFile.is_open()) {
        // Write to the file
        authFile << username << ";" << hashValue << "\n";

        authFile.close();
    } else {
        std::cerr << "Error opening file." << std::endl;
    }
}

void registerFunction() {
    std::string password, username;
    std::cout << "Enter your username" << "\n";
    std::cin >> username;

    std::cout << "Enter your password" << "\n";
    std::cin >> password;
    if (checkIfUsernameExists(username)) {
        saveToPasswdFile(username, password);
        std::cout << "New user "<<username<<" saved !" << "\n";

    }
}

bool checkUsernameAndPassword(const std::string &username, const std::string &password) {
    std::ifstream authFile("passwd.txt");
    if (authFile.is_open()) {
        std::cout << "Checking if username exists... " << std::endl;

        // check username then if exists check password
        std::string line;
        while (std::getline(authFile, line)) {
            std::string existingUser = line.substr(0, line.find(';'));
            if (username == existingUser) {
                std::string savedPassword = line.substr(line.find(';')+1, line.size());
                std::string hashedInputPassword = std::to_string(djb2Hash(password.c_str()));
                if (savedPassword == hashedInputPassword) {
                    return true;
                }

            }
        }

        authFile.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }
    return false;
}

void loginFunction() {
    std::string password, username;
    std::cout << "Enter your username" << "\n";
    std::cin >> username;

    std::cout << "Enter your password" << "\n";
    std::cin >> password;

    if (checkUsernameAndPassword(username, password)) {
        std::cout << "Congrats you're in !" << std::endl;
    } else {
        std::cout << "Wrong username/password" << std::endl;
    }

}

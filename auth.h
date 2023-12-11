#ifndef AUTH_H
#define AUTH_H

#include <string>

unsigned long djb2Hash(const char *str);
bool checkIfUsernameExists(const std::string &username);
void saveToPasswdFile(const std::string &username, const std::string &password);
void registerFunction();
bool checkUsernameAndPassword(const std::string &username, const std::string &password);
void loginFunction();

#endif // AUTH_H

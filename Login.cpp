#include "Login.h"
#include <fstream>
#include <iostream>

// constructor
Login::Login(const std::string& file) : credentialsFile(file) {
    loadCredentials();
}

// stores data as hash function
std::string Login::hashPassword(const std::string& password) {
    unsigned long hash = 5381; // a common initial value
    for (char c : password) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return std::to_string(hash);
}

// loads all logins from file
void Login::loadCredentials() {
    std::ifstream file(credentialsFile);
    if (!file.is_open()) {
        std::cerr << "Warning: Login details not found. Creating a new one.\n";
        std::ofstream newFile(credentialsFile);
        newFile.close();
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        size_t delimiterPos = line.find(':');
        if (delimiterPos != std::string::npos) {
            std::string username = line.substr(0, delimiterPos);
            std::string hashedPassword = line.substr(delimiterPos + 1);
            credentials[username] = hashedPassword;
        }
    }
    file.close();
}

// save credentials to file
void Login::saveCredentials() {
    std::ofstream file(credentialsFile);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open credentials file for writing.\n";
        return;
    }

    for (const auto& pair : credentials) {
        file << pair.first << ":" << pair.second << "\n";
    }
    file.close();
}

// authenticate a user
bool Login::loginUser(const std::string& username, const std::string& password) {
    auto it = credentials.find(username);
    if (it == credentials.end()) {
        std::cout << "Invalid username.\n";
        return false;
    }

    std::string hashedInputPassword = hashPassword(password);
    
    //login in successful
    if (it->second == hashedInputPassword) {
        std::cout << "Login successful!\n";
        return true;
        
        //password wrong
    } else {
        std::cout << "Invalid password.\n";
        return false;
    }
}

// register a new user
bool Login::registerUser(const std::string& username, const std::string& password) {
    // Username taken 
    if (userExists(username)) {
        std::cout << "Username already exists.\n";
        return false;
    }

    //registered
    std::string hashedPassword = hashPassword(password);
    credentials[username] = hashedPassword;
    saveCredentials();
    std::cout << "User registered successfully!\n";
    return true;
}

// check if a user exists
bool Login::userExists(const std::string& username) {
    return credentials.find(username) != credentials.end();
}

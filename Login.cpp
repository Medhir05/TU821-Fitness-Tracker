#include "Login.h"
#include <fstream>
#include <iostream>
#include <vector>

// constructor

//
Login::Login(const std::string& file) : credentialsFile(file) {
    loadCredentials();
}

// loads all logins from file
void Login::loadCredentials() {
    //opens credentials files for containing usernames and passwords
    std::ifstream file(credentialsFile);
    //Creates new file
    if (!file.is_open()) {
        std::cerr << "Warning, Login details not found. Creating a new file.\n";
        std::ofstream newFile(credentialsFile);
        newFile.close();
        return;
    }

    std::string username, password;
    while (file >> username >> password) {
        credentials.push_back(std::make_pair(username, password));
    }
    file.close();
}

// save credentials to file
void Login::saveCredentials() {
    std::ofstream file(credentialsFile);
    //if theres no credentials file
    if (!file.is_open()) {
        std::cerr << "Error: Could not open credentials file for reading usernames and passwords.\n";
        return;
    }

    
    // Pair first will be username and pair second is the password const auto automatically decides type of variable
    for (const auto& pair : credentials) {
        file << pair.first << " " << pair.second << "\n";
    }
    file.close();
}

// authenticate a user
bool Login::loginUser(const std::string& username, const std::string& password) {
    for (const auto& pair : credentials) {
        // Checks for username
        if (pair.first == username) {
            //Checks for password
            if (pair.second == password) {
                // Logged in
                std::cout << "Login successful!\n";
                return true;
            } else {
                //Login failure
                std::cout << "Password is wrong.\n";
                return false;
            }
        }
    }
    //if username doesnt match
    std::cout << "Invalid username.\n";
    return false;
}

// register a new user
bool Login::registerUser(const std::string& username, const std::string& password) {
    if (userExists(username)) {
        std::cout << "Username already exists.\n";
        return false;
    }

    //User register for making a username and password when succesful
    credentials.push_back(std::make_pair(username, password));
    saveCredentials();
    std::cout << "User registered successfully!\n";
    return true;
}

// check if a user exists
bool Login::userExists(const std::string& username) {
    for (const auto& pair : credentials) {
        if (pair.first == username) {
            return true;
        }
    }
    return false;
}

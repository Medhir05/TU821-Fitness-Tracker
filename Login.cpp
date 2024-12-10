#include "Login.h"
#include <fstream>
#include <iostream>

/**
 * @class Login
 * @brief Manages user login and registration by storing credentials securely.
 */

/**
 * @brief Constructs a Login object and loads credentials from a file.
 * @param file The path to the file storing user credentials.
 */
Login::Login(const std::string& file) : credentialsFile(file) {
    loadCredentials();
}

/**
 * @brief Hashes a given password using a simple hash function.
 * @param password The plaintext password to hash.
 * @return A hashed version of the password as a string.
 */
std::string Login::hashPassword(const std::string& password) {
    unsigned long hash = 5381; // A common initial value
    for (char c : password) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return std::to_string(hash);
}

/**
 * @brief Loads user credentials from the credentials file into memory.
 * If the file does not exist, it creates a new one.
 */
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

/**
 * @brief Saves user credentials from memory to the credentials file.
 */
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

/**
 * @brief Authenticates a user with a given username and password.
 * @param username The username of the user.
 * @param password The plaintext password of the user.
 * @return True if login is successful, false otherwise.
 */
bool Login::loginUser(const std::string& username, const std::string& password) {
    auto it = credentials.find(username);
    if (it == credentials.end()) {
        std::cout << "Invalid username.\n";
        return false;
    }

    std::string hashedInputPassword = hashPassword(password);

    if (it->second == hashedInputPassword) {
        std::cout << "Login successful!\n";
        return true;
    } else {
        std::cout << "Invalid password.\n";
        return false;
    }
}

/**
 * @brief Registers a new user with a given username and password.
 * @param username The desired username.
 * @param password The plaintext password for the new user.
 * @return True if registration is successful, false if the username is already taken.
 */
bool Login::registerUser(const std::string& username, const std::string& password) {
    if (userExists(username)) {
        std::cout << "Username already exists.\n";
        return false;
    }

    std::string hashedPassword = hashPassword(password);
    credentials[username] = hashedPassword;
    saveCredentials();
    std::cout << "User registered successfully!\n";
    return true;
}

/**
 * @brief Checks if a user exists in the system.
 * @param username The username to check.
 * @return True if the user exists, false otherwise.
 */
bool Login::userExists(const std::string& username) {
    return credentials.find(username) != credentials.end();
}

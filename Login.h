#ifndef LOGIN_H
#define LOGIN_H

#include <string>
#include <unordered_map>

class Login {
private:
    std::unordered_map<std::string, std::string> credentials; // Stores username:hashed_password
    std::string credentialsFile; // Path to credentials file

    // function to hash passwords
    std::string hashPassword(const std::string& password);

    // function to load credentials from a file
    void loadCredentials();

    // function to save credentials to a file
    void saveCredentials();

public:
    // constructor
    Login(const std::string& file);

    // login function
    bool loginUser(const std::string& username, const std::string& password);

    // registration function
    bool registerUser(const std::string& username, const std::string& password);

    // function to check if a user exists
    bool userExists(const std::string& username);
};

#endif // LOGIN_H

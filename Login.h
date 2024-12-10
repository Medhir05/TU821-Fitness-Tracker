#ifndef LOGIN_H
#define LOGIN_H

#include <string>
#include <vector>


class Login {
private:
    std::vector<std::pair<std::string, std::string>> credentials; // Stores username and password pairs in a vector
    std::string credentialsFile; // Path to credentials file

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

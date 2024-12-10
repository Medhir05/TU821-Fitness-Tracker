#ifndef LOGIN_H
#define LOGIN_H

#include <string>
#include <unordered_map>

/**
 * @class Login
 * @brief Handles user authentication and registration using a file-based storage system.
 */
class Login {
private:
    /**
     * @brief Stores the mapping of usernames to hashed passwords.
     */
    std::unordered_map<std::string, std::string> credentials;

    /**
     * @brief Path to the file where credentials are stored.
     */
    std::string credentialsFile;

    /**
     * @brief Hashes a given password using a simple hash function.
     * @param password The plaintext password to hash.
     * @return A hashed version of the password as a string.
     */
    std::string hashPassword(const std::string& password);

    /**
     * @brief Loads user credentials from the credentials file into memory.
     */
    void loadCredentials();

    /**
     * @brief Saves user credentials from memory to the credentials file.
     */
    void saveCredentials();

public:
    /**
     * @brief Constructs a Login object and initializes it with the given credentials file.
     * @param file The path to the file storing user credentials.
     */
    Login(const std::string& file);

    /**
     * @brief Authenticates a user with a given username and password.
     * @param username The username of the user.
     * @param password The plaintext password of the user.
     * @return True if login is successful, false otherwise.
     */
    bool loginUser(const std::string& username, const std::string& password);

    /**
     * @brief Registers a new user with a given username and password.
     * @param username The desired username.
     * @param password The plaintext password for the new user.
     * @return True if registration is successful, false if the username is already taken.
     */
    bool registerUser(const std::string& username, const std::string& password);

    /**
     * @brief Checks if a user exists in the system.
     * @param username The username to check.
     * @return True if the user exists, false otherwise.
     */
    bool userExists(const std::string& username);
};

#endif // LOGIN_H

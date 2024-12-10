/**
 *Test record is available on github: https://github.com/Medhir05/TU821-Fitness-Tracker. User manual is available on the README file in the zip. Doxygen documentation is also available in the zip file. This submission is for: Medhir Gulati, Jack Clarke, David Costello.
 * @file main.cpp
 * @brief Entry point for the fitness tracker application.
 *
 * This program allows users to record their workout plan for multiple weeks,
 * specifying exercises, sets, and reps for each day of the week.
 */

#include "weeklyWorkout.h"
#include "Exercise.h"
#include "progress.h"
#include "Login.h"
#include <vector>
#include <iostream>

/**
 * @brief Main function for the fitness tracker application.
 *
 * Allows the user to input workout data for multiple weeks.
 *
 * @return int Returns 0 upon successful execution.
 */
int main() {
   
    
    // login system
    Login loginSystem("credentials.txt");

    //variables for login system
        int choice;
        std::string yn, currentUser, username, password;

    
  //asks user what they want to do
        while (true) {
            std::cout << "1. Register\n2. Login\n3. Guest\n4. Exit Enter your choice (1/2/3/4): ";
            std::cin >> choice;

            //login
            if (choice == 1) {
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;

                
             //Register
                loginSystem.registerUser(username, password);
            } else if (choice == 2) {
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;
                loginSystem.loginUser(username, password);
                currentUser = username;
                break; 
            
                //guest feature
            } else if (choice == 3) {
                currentUser = "guest";
                std::cout << "As a guest your files may be overwritten at any time.\nDo you wish to continue (y/n): ";
                std::cin >> yn;

                //continue as guest
                if (yn == "y" || yn == "Y") {  //if answer is y or Y it will continue if anything else return 0
                    break;
                } else {
                    return 0;
                }
            }
            //Exit stops program
             else if (choice == 4) {
                return 0;}
            
                else {
                std::cout << "Invalid choice. Try again.\n";
            
            }
        }
    
    int numWeeks;  // Number of weeks the user wants to track
    std::cout << "How many weeks of workout data would you like to enter? ";
    std::cin >> numWeeks;
    std::cin.ignore();  // to fix new line issues in terminal

    // Vector to store WeeklyWorkout objects for multiple weeks
    std::vector<WeeklyWorkout> allWeeks;

    // Loop for each week
    for (int weekIndex = 0; weekIndex < numWeeks; ++weekIndex) {
        WeeklyWorkout weeklyWorkout;  // Create a new WeeklyWorkout object
        const std::vector<std::string> daysOfWeek = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

        std::cout << "\nEntering data for Week " << (weekIndex + 1) << ":\n";

        // Loop for each day of the week
        for (int dayIndex = 0; dayIndex < 7; ++dayIndex) {
            std::cout << "\nEnter the routine for " << daysOfWeek[dayIndex] << ":\n";

            int numExercises;
            std::cout << "How many exercises for " << daysOfWeek[dayIndex] << "? ";
            std::cin >> numExercises;
            std::cin.ignore();  // // to fix new line issues in terminal

            // Loop for each exercise
            for (int i = 0; i < numExercises; ++i) {
                std::string exerciseName;
                int sets, reps;

                std::cout << "Enter the name of exercise #" << (i + 1) << ": ";
                std::getline(std::cin, exerciseName);  // Read the exercise name

                std::cout << "Enter the number of sets for " << exerciseName << ": ";
                std::cin >> sets;

                std::cout << "Enter the number of reps for " << exerciseName << ": ";
                std::cin >> reps;
                std::cin.ignore();  // // to fix new line issues in terminal

                Exercises exercise(exerciseName, sets, reps, numExercises); // adding this data to the overloaded constructor.
                weeklyWorkout.addExerciseToDay(dayIndex, exercise);
            }
        }

        allWeeks.push_back(weeklyWorkout);  // Add the week's data to the vector
    }

    // Display all weeks
    for (int weekIndex = 0; weekIndex < numWeeks; ++weekIndex) {
        std::cout << "\nWeek " << (weekIndex + 1) << ":\n";
        allWeeks[weekIndex].displayWeeklyWorkout();
    }

    // Save each week's data to a separate file
    for (int weekIndex = 0; weekIndex < numWeeks; ++weekIndex) {
        std::string filename = currentUser + "_WeeklyWorkoutPlan_Week_" + std::to_string(weekIndex + 1) + ".txt";
        allWeeks[weekIndex].saveWeeklyWorkoutToFile(filename);
    }

    int calories_burned;
    int minutes_training;
    std::cout << "How many calories do you plan on burning in total this week?\n";
    std::cin>> calories_burned;
    std::cout << "How many minutes did you plan on train this week?\n";
    std::cin >> minutes_training;

    FitnessTracker tracker(calories_burned, minutes_training);

    std::cout << "Did you do any other activities this week? (y/n): ";
char moreActivities;
std::cin >> moreActivities;
std::cin.ignore(); // Clear newline from input buffer

while (moreActivities == 'y' || moreActivities == 'Y') {
    std::string dayOfWeek, exercise;
    int duration, calories;

    std::cout << "Enter the day of the week (e.g., Monday, Tuesday): ";
    std::getline(std::cin, dayOfWeek);

    std::cout << "Enter the type of exercise: ";
    std::getline(std::cin, exercise);

    std::cout << "Enter the duration of the activity (in minutes): ";
    std::cin >> duration;

    std::cout << "Enter the calories burned: ";
    std::cin >> calories;

    // Add workout using day of the week as the date
    tracker.addWorkout(dayOfWeek, exercise, duration, calories);

    std::cout << "Do you want to add another activity? (y/n): ";
    std::cin >> moreActivities;
    std::cin.ignore(); // Clear newline
}

    // Show all workouts
    tracker.showWorkouts();

    // Show progress summary
    tracker.showProgressSummary();

    // Save workouts to file
    tracker.saveWorkoutsToFile();

    // Load workouts from file (if any)
    tracker.loadWorkoutsFromFile();
    
    // User logout + program end
    std::cout << currentUser << " has now been logged out.\nThank you for using Fitness tracker!\n";

    return 0;
}

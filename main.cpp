/**
 * @file main.cpp
 * @brief Entry point for the fitness tracker application.
 *
 * This program allows users to record their workout plan for multiple weeks,
 * specifying exercises, sets, and reps for each day of the week.
 */

#include "WeeklyWorkout.h"
#include "Exercises.h"
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
    int numWeeks;  // Number of weeks the user wants to track
    std::cout << "How many weeks of workout data would you like to enter? ";
    std::cin >> numWeeks;
    std::cin.ignore();  // Consume the newline character left in the buffer

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
            std::cin.ignore();  // Consume the newline character left in the buffer

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
                std::cin.ignore();  // Consume the newline character left in the buffer

                Exercises exercise(exerciseName, sets, reps, numExercises);
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
        std::string filename = "WeeklyWorkoutPlan_Week_" + std::to_string(weekIndex + 1) + ".txt";
        allWeeks[weekIndex].saveWeeklyWorkoutToFile(filename);
    }

    return 0;
}

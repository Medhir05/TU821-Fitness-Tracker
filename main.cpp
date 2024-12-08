/**
 * @file main.cpp
 * @brief Entry point for the fitness tracker application.
 * 
 * This program allows users to record their workout plan by
 * specifying exercises, sets, and reps for each day of the week.
 */
#include "WeeklyWorkout.h"
#include "Exercises.h"
/**
 * @brief Main function for the fitness tracker application.
 * 
 * Prompts the user to input their workout routine for each day of the week,
 * stores the data, displays the weekly workout plan, and saves it to a file.
 * 
 * @return int Returns 0 upon successful execution.
 */



int main() {
    WeeklyWorkout weeklyWorkout; ///< object for managing weekly workouts 
    const std::vector<std::string> daysOfWeek = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };// vector with days of week

    // Loop through each day 
    for (int dayIndex = 0; dayIndex < 7; ++dayIndex) {
        std::cout << "\nEnter the routine for " << daysOfWeek[dayIndex] << ":\n";

        int numExercises; ///< number of exercises for the day
        std::cout << "How many exercises for " << daysOfWeek[dayIndex] << "? "; // how many exercises for each day
        std::cin >> numExercises;  // store value 
        std::cin.ignore(); // Avoid newline issues

        for (int i = 0; i < numExercises; ++i) {
            std::string exerciseName;
            int sets, reps;

            // Get exercise details
            std::cout << "Enter the name of exercise #" << (i + 1) << ": ";
            std::getline(std::cin, exerciseName);

            std::cout << "Enter the number of sets for " << exerciseName << ": ";
            std::cin >> sets;

            std::cout << "Enter the number of reps for " << exerciseName << ": ";
            std::cin >> reps;
            std::cin.ignore(); // Avoid newline issues

            // Create an Exercises object and add it to the current day's routine
            Exercises exercise(exerciseName, sets, reps, numExercises);
            weeklyWorkout.addExerciseToDay(dayIndex, exercise);
        }
    }

    // Display the weekly workout plan
    std::cout << "\nYour weekly workout plan:\n";
    weeklyWorkout.displayWeeklyWorkout();

    std::string filename = "WeeklyWorkoutPlan.txt";
    weeklyWorkout.saveWeeklyWorkoutToFile(filename);

    return 0;
}

#include "WeeklyWorkout.h"
#include "Exercises.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
    WeeklyWorkout weeklyWorkout;
    const std::vector<std::string> daysOfWeek = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

    for (int dayIndex = 0; dayIndex < 7; ++dayIndex) {
        std::cout << "\nEnter the routine for " << daysOfWeek[dayIndex] << ":\n";

        int numExercises;
        std::cout << "How many exercises for " << daysOfWeek[dayIndex] << "? ";
        std::cin >> numExercises;
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

    return 0;
}

/**
 * @file WeeklyWorkout.cpp
 * @brief Implementation of the WeeklyWorkout class.
 */

#include "WeeklyWorkout.h"
#include <iostream>
#include <fstream>

/**
 * @brief Constructor that initializes a weekly plan with 7 empty days.
 */
WeeklyWorkout::WeeklyWorkout() : week(7) {}

/**
 * @brief Adds an exercise to a specific day of the week.
 * @param dayIndex Index of the day (0 = Monday, ..., 6 = Sunday).
 * @param exercise The exercise to add.
 */
void WeeklyWorkout::addExerciseToDay(int dayIndex, const Exercises& exercise) {
    if (dayIndex >= 0 && dayIndex < 7) {
        week[dayIndex].push_back(exercise); // Add the exercise to the vector. 
    }
}

/**
 * @brief Displays the weekly workout plan.
 */

void WeeklyWorkout::displayWeeklyWorkout() const {
    for (size_t i = 0; i < week.size(); ++i) {
        std::cout << daysOfWeek[i] << ":\n";
        if (week[i].empty()) {
            std::cout << "  No exercises scheduled.\n"; // user said there were 0 exercises for the day
        } else {
            for (const auto& exercise : week[i]) {
                std::cout << "  Exercise: " << exercise.getExcercises()
                          << ", Sets: " << exercise.getSets()
                          << ", Reps: " << exercise.getReps() << "\n";
            }
        }
        std::cout << "\n";
    }
}


/**
 * @brief Saves the weekly workout plan to a file.
 * @param filename Name of the file to save the plan.
 */
void WeeklyWorkout::saveWeeklyWorkoutToFile(const std::string& filename) const {
    std::ofstream outFile(filename); // Open file for writing

    if (!outFile) {
        std::cerr << "Error: Could not open file " << filename << " for writing.\n"; //error
        return;
    }

    for (size_t i = 0; i < week.size(); ++i) { // goes through the entire vector. Size of the vector shows the amount of exercises
        outFile << daysOfWeek[i] << ":\n";
        if (week[i].empty()) {
            outFile << "  No exercises scheduled.\n"; // user said there were 0 exercises for the day
        } else {
            for (const auto& exercise : week[i]) {
                outFile << "  Exercise: " << exercise.getExcercises()
                        << ", Sets: " << exercise.getSets()
                        << ", Reps: " << exercise.getReps() << "\n";
            }
        }
        outFile << "\n";
    }

    outFile.close(); // Close the file
    std::cout << "Workout plan saved to " << filename << "\n";
}

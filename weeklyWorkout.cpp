#include "WeeklyWorkout.h"
#include <iostream>
#include <fstream>

//Initialize the week with 7 empty vectors (one for each day)
WeeklyWorkout::WeeklyWorkout() : week(7) {}

void WeeklyWorkout::addExerciseToDay(int dayIndex, const Exercises& exercise) {
    if (dayIndex >= 0 && dayIndex < 7) {
        week[dayIndex].push_back(exercise); // Add the exercise to the vector. 
    }
}

void WeeklyWorkout::displayWeeklyWorkout() const {
    for (size_t i = 0; i < week.size(); ++i) {
        std::cout << daysOfWeek[i] << ":\n";
        if (week[i].empty()) {
            std::cout << "  No exercises scheduled.\n";
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

void WeeklyWorkout::saveWeeklyWorkoutToFile(const std::string& filename) const {
    std::ofstream outFile(filename); // Open file for writing

    if (!outFile) {
        std::cerr << "Error: Could not open file " << filename << " for writing.\n";
        return;
    }

    for (size_t i = 0; i < week.size(); ++i) { // goes through the entire vector. Size of the vector shows the amount of exercises
        outFile << daysOfWeek[i] << ":\n";
        if (week[i].empty()) {
            outFile << "  No exercises scheduled.\n";
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

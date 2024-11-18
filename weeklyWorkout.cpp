#include "WeeklyWorkout.h"
#include <iostream>

// Constructor: Initialize the week with 7 empty vectors (one for each day)
WeeklyWorkout::WeeklyWorkout() : week(7) {}

void WeeklyWorkout::addExerciseToDay(int dayIndex, const Exercises& exercise) {
    if (dayIndex >= 0 && dayIndex < 7) {
        week[dayIndex].push_back(exercise); // Add the exercise to the day's list
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

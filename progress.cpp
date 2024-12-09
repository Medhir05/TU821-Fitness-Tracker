#include "progress.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>

/**
 * @class Workout
 * @brief Represents a single workout session.
 */
Workout::Workout(std::string date, std::string exercise, int duration, int calories)
    : date(date), exercise(exercise), duration(duration), caloriesBurned(calories) {}

/**
 * @class FitnessGoal
 * @brief Represents a fitness goal in terms of calories and duration.
 */
FitnessGoal::FitnessGoal(int calories, int duration)
    : targetCalories(calories), targetDuration(duration) {}

/**
 * @class FitnessTracker
 * @brief Manages a collection of workouts and tracks progress towards fitness goals.
 */

/**
 * @brief Constructs a FitnessTracker object with a specific fitness goal.
 * @param targetCalories The target number of calories to burn.
 * @param targetDuration The target duration of workouts in minutes.
 */
FitnessTracker::FitnessTracker(int targetCalories, int targetDuration)
    : goal(targetCalories, targetDuration) {}

/**
 * @brief Adds a workout to the tracker.
 * @param date The date of the workout (e.g., "Monday").
 * @param exercise The type of exercise performed.
 * @param duration The duration of the workout in minutes.
 * @param calories The calories burned during the workout.
 */
void FitnessTracker::addWorkout(std::string date, std::string exercise, int duration, int calories) {
    workouts.push_back(Workout(date, exercise, duration, calories));
}

/**
 * @brief Displays the history of all recorded workouts.
 */
void FitnessTracker::showWorkouts() {
    std::cout << "\nWorkout History:\n";
    for (const auto& workout : workouts) {
        std::cout << "Date: " << workout.date
                  << ", Exercise: " << workout.exercise
                  << ", Duration: " << workout.duration << " mins"
                  << ", Calories Burned: " << workout.caloriesBurned << "\n";
    }
}

/**
 * @brief Shows a summary of progress towards fitness goals.
 */
void FitnessTracker::showProgressSummary() {
    int totalDuration = 0;
    int totalCalories = 0;

    for (const auto& workout : workouts) {
        totalDuration += workout.duration;
        totalCalories += workout.caloriesBurned;
    }

    std::cout << "\nProgress Summary:\n";
    std::cout << "Total Duration: " << totalDuration << " mins\n";
    std::cout << "Total Calories Burned: " << totalCalories << " kcal\n";

    if (totalCalories >= goal.targetCalories) {
        std::cout << "Goal reached for calories!\n";
    } else {
        std::cout << "Calories goal remaining: " << (goal.targetCalories - totalCalories) << " kcal\n";
    }

    if (totalDuration >= goal.targetDuration) {
        std::cout << "Goal reached for workout duration!\n";
    } else {
        std::cout << "Duration goal remaining: " << (goal.targetDuration - totalDuration) << " mins\n";
    }
}

/**
 * @brief Saves all recorded workouts to a file.
 *
 * Appends the workout data to "workout_history.txt".
 */
void FitnessTracker::saveWorkoutsToFile() {
    std::ofstream file("workout_history.txt", std::ios::app);

    if (file.is_open()) {
        for (const auto& workout : workouts) {
            file << workout.date << ", "
                 << workout.exercise << ", "
                 << workout.duration << ", "
                 << workout.caloriesBurned << "\n";
        }
        file.close();
        std::cout << "Workouts saved to file.\n";
    } else {
        std::cout << "Failed to open file for saving.\n";
    }
}

/**
 * @brief Loads workouts from a file into the tracker.
 *
 * Reads the workout data from "workout_history.txt". If the file does not exist,
 * it notifies the user.
 */
void FitnessTracker::loadWorkoutsFromFile() {
    std::ifstream file("workout_history.txt");
    std::string date, exercise;
    int duration, calories;

    if (file.is_open()) {
        while (file >> date >> exercise >> duration >> calories) {
            workouts.push_back(Workout(date, exercise, duration, calories));
        }
        file.close();
        std::cout << "Workouts loaded from file.\n";
    } else {
        std::cout << "No workout history found.\n";
    }
}

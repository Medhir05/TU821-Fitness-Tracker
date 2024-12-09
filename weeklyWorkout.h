/**
 * @file WeeklyWorkout.h
 * @brief Declaration of the WeeklyWorkout class.
 * 
 * This class manages the weekly workout plan, allowing users to add exercises
 * to specific days and view or save the plan.
 */

#ifndef WEEKLYWORKOUT_H
#define WEEKLYWORKOUT_H

#include <string>
#include <vector>
#include "Exercises.h"
/**
 * @class WeeklyWorkout
 * @brief Manages a weekly workout plan.
 * The class provides functionalities to add, display, and save a workout plan.
 * @dotfile diagrams/class_weeklyworkout.dot
 */
class WeeklyWorkout {
public:
    /**
     * @brief Constructor that initializes a weekly plan with 7 days.
     */
    WeeklyWorkout();
    /**
     * @brief Adds an exercise to a specific day of the week.
     * @param dayIndex Index of the day (0 = Monday, ..., 6 = Sunday).
     * @param exercise The exercise to add.
     */
    void addExerciseToDay(int dayIndex, const Exercises& exercise);
    /**
     * @brief Displays the entire weekly workout plan.
     * 
     * Outputs the workout plan for all seven days to the console. If a day has
     * no exercises scheduled, it indicates that the day is empty.
     * 
     * @note This function is intended for quick reference and does not save the plan to a file.
     */
    void displayWeeklyWorkout() const;
    /**
     * @brief Displays the workout chosen in the console. 
     * 
     * Writes the entire workout plan, including the exercises for each day.
     * If a day has no exercises scheduled, it indicates that the day is empty in the file.
     */
    void saveWeeklyWorkoutToFile(const std::string& filename) const;
    /**
     * @brief Saves the weekly workout plan to a text file.
     * 
     * Writes the entire workout plan, including the exercises for each day, to a specified file.
     * If a day has no exercises scheduled, it indicates that the day is empty in the file.
     * 
     * @param filename The name of the file where the workout plan is saved.
     * 
     * @note The file is overwritten if it already exists.  
     */

private:
    std::vector<std::vector<Exercises>> week; // 7 days, each with a list of exercises
    const std::vector<std::string> daysOfWeek = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
};

#endif

#ifndef PROGRESS_H
#define PROGRESS_H

#include <string>
#include <vector>

/**
 * @struct Workout
 * @brief Represents a single workout session.
 */
struct Workout {
    std::string date;        ///< The date of the workout (e.g., "Monday").
    std::string exercise;    ///< The type of exercise performed.
    int duration;            ///< The duration of the workout in minutes.
    int caloriesBurned;      ///< The number of calories burned during the workout.

    /**
     * @brief Constructs a Workout object.
     * @param date The date of the workout.
     * @param exercise The type of exercise performed.
     * @param duration The duration of the workout in minutes.
     * @param calories The number of calories burned during the workout.
     */
    Workout(std::string date, std::string exercise, int duration, int calories);
};

/**
 * @struct FitnessGoal
 * @brief Represents a fitness goal in terms of calories and workout duration.
 */
struct FitnessGoal {
    int targetCalories;      ///< The target number of calories to burn.
    int targetDuration;      ///< The target workout duration in minutes.

    /**
     * @brief Constructs a FitnessGoal object.
     * @param calories The target number of calories to burn.
     * @param duration The target workout duration in minutes.
     */
    FitnessGoal(int calories, int duration);
};

/**
 * @class FitnessTracker
 * @brief Manages fitness progress by tracking workouts and goals.
 */
class FitnessTracker {
private:
    std::vector<Workout> workouts; ///< List of recorded workouts.
    FitnessGoal goal;             ///< Fitness goal for calories and duration.

public:
    /**
     * @brief Constructs a FitnessTracker object with a specified fitness goal.
     * @param targetCalories The target number of calories to burn.
     * @param targetDuration The target workout duration in minutes.
     */
    FitnessTracker(int targetCalories, int targetDuration);

    /**
     * @brief Adds a workout to the tracker.
     * @param date The date of the workout (e.g., "Monday").
     * @param exercise The type of exercise performed.
     * @param duration The duration of the workout in minutes.
     * @param calories The calories burned during the workout.
     */
    void addWorkout(std::string date, std::string exercise, int duration, int calories);

    /**
     * @brief Displays all recorded workouts in the tracker.
     */
    void showWorkouts();

    /**
     * @brief Displays a summary of progress towards fitness goals.
     */
    void showProgressSummary();

    /**
     * @brief Saves all recorded workouts to a file.
     *
     * Appends workout data to a file named "workout_history.txt".
     */
    void saveWorkoutsToFile();

    /**
     * @brief Loads workouts from a file into the tracker.
     *
     * Reads workout data from "workout_history.txt". If the file does not exist,
     * it notifies the user.
     */
    void loadWorkoutsFromFile();
};

#endif // PROGRESS_H

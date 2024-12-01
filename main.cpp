#include "WeeklyWorkout.h"
#include "Exercises.h"


int main() {
    WeeklyWorkout weeklyWorkout; // object for the class 
    const std::vector<std::string> daysOfWeek = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };// vector with days of week

    // Loop through each day 
    for (int dayIndex = 0; dayIndex < 7; ++dayIndex) {
        std::cout << "\nEnter the routine for " << daysOfWeek[dayIndex] << ":\n";

        int numExercises; // number of exercises variable
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

#ifndef WEEKLYWORKOUT_H
#define WEEKLYWORKOUT_H

#include <string>
#include <vector>
#include "Exercises.h"

class WeeklyWorkout {
public:
    WeeklyWorkout();
    void addExerciseToDay(int dayIndex, const Exercises& exercise);
    void displayWeeklyWorkout() const;
    void saveWeeklyWorkoutToFile(const std::string& filename) const;



private:
    std::vector<std::vector<Exercises>> week; // 7 days, each with a list of exercises
    const std::vector<std::string> daysOfWeek = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
};

#endif

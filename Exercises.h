/**
 * @file Exercises.h
 * @brief Declaration of the Exercises class.
 * 
 * This class manages individual exercise details, including name, sets, reps,
 * and the total number of exercises.
 */

#ifndef EXERCISES_H
#define EXERCISES_H



#pragma once

#include <string> 
#include <iostream> 
#include <vector>

/**
 * @class Exercises
 * @brief Represents an individual exercise with its properties.   
 * The class is used to define and manage individual exercises.
 * @dotfile diagrams/class_exercises.dot
 */
class Exercises
{
public:
    /**
     * @brief Default constructor.
     */
    Exercises(); 
    /**
     * @brief Destructor.
     */
    ~Exercises();
    /**
     * @brief Overloaded constructor.
     * @param val_a Name of the exercise.
     * @param val_b Number of sets.
     * @param val_c Number of reps.
     * @param val_d Total number of exercises.
     */
    Exercises(std::string val_a,int val_b, int val_c, int val_d );
    // getters and setters
    int getSets() const {return sets;}
    void setSets(int value) {sets = value;} 

    int getReps() const {return reps;}
    void setReps(int value) {reps = value;} 
    
    std::string getExcercises() const {return exerciseName;}
    void setExercises(std::string value) {exerciseName = value;}

    void exerciseNum(int amount); ///< total number of exercises
    void exercise_Name(std::string name); ///< name of exercise 
    void setsNum(int amount);  ///< number of sets
    void repsNum(int amount); ///< number of reps 
    //void displayWorkout(); 

private:
        std::string exerciseName; 
        int sets; 
        int reps; 
        int numExercises;
};

#endif
/**
 * @file Exercises.cpp
 * @brief Implementation of the Exercises class.
 * 
 * Contains definitions for the member functions of the Exercises class, which
 * represents an individual exercise with its name, sets, reps, and other details.
 */

#include "Exercises.h"
#include <iostream>
#include <string> 
#include <vector>


/**
 * @brief Default constructor for the Exercises class.
 * 
 * Initializes an exercise object with default values:
 * - `sets` and `reps` are set to 0.
 * - `numExercises` is set to 0.
 * - `exerciseName` is initialized as an empty string.
 */
Exercises::Exercises() // Class 
{
    sets = 0; 
    reps = 0;
    numExercises=0;
    exerciseName = " "; 
}


/**
 * @brief Parameterized constructor for the Exercises class.
 * 
 * Allows creating an exercise object with specific values.
 * 
 * @param val_a The name of the exercise.
 * @param val_b The number of sets for the exercise.
 * @param val_c The number of reps per set.
 * @param val_d The total number of exercises in the routine.
 */
Exercises::Exercises(std::string val_a,int val_b, int val_c, int val_d ) // Class overloading 
{
    exerciseName = val_a; 
    sets = val_b;
    reps = val_c;
    numExercises = val_d;

}
/**
 * @brief Destructor for the Exercises class.
 * 
 * Currently performs no specific cleanup as no dynamic memory is used.
 */
Exercises::~Exercises()
{

}
/**
 * @brief Sets the number of exercises.
 * 
 * Updates the `amount` parameter with the total number of exercises in the routine.
 * 
 * @param amount Reference to an integer to store the total number of exercises.
 */
void Exercises::exerciseNum(int amount) // Function for number of exercises 
{
    amount = numExercises;
}
/**
 * @brief Sets the name of the exercise.
 * 
 * Updates the `name` parameter with the name of the exercise.
 * 
 * @param name Reference to a string to store the exercise name.
 */
void Exercises::exercise_Name(std::string name) 
{
    name = exerciseName; 
}
/**
 * @brief Sets the number of sets.
 * 
 * Updates the `amount` parameter with the number of sets for the exercise.
 * 
 * @param amount Reference to an integer to store the number of sets.
 */
void Exercises::setsNum(int amount) // Function for number of sets 
{
    amount = sets;
}
/**
 * @brief Sets the number of reps.
 * 
 * Updates the `amount` parameter with the number of reps per set for the exercise.
 * 
 * @param amount Reference to an integer to store the number of reps per set.
 */
void Exercises::repsNum(int amount) // Function for number of reps 
{
    amount = reps; 
}





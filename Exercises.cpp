#include "Exercises.h"
#include <iostream>
#include <string> 
#include <vector>

Exercises::Exercises() // Class 
{
    sets = 0; 
    reps = 0;
    numExercises=0;
    exerciseName = " "; 
}

Exercises::Exercises(std::string val_a,int val_b, int val_c, int val_d ) // Class overloading 
{
    exerciseName = val_a; 
    sets = val_b;
    reps = val_c;
    numExercises = val_d;

}

Exercises::~Exercises()
{

}

void Exercises::exerciseNum(int amount) // Function for number of exercises 
{
    amount = numExercises;
}

void Exercises::exercise_Name(std::string name) 
{
    name = exerciseName; 
}

void Exercises::setsNum(int amount) // Function for number of sets 
{
    amount = sets;
}

void Exercises::repsNum(int amount) // Function for number of reps 
{
    amount = reps; 
}





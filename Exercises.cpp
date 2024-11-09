#include "Exercises.h"
#include <iostream>
#include <string> 
#include <vector>

Exercises::Exercises()
{
    sets = 0; 
    reps = 0;
    numExercises=0;
    exerciseName = " "; 
}

Exercises::Exercises(std::string val_a,int val_b, int val_c, int val_d )
{
    exerciseName = val_a; 
    sets = val_b;
    reps = val_c;
    numExercises = val_d;

}

Exercises::~Exercises()
{

}

void Exercises::exerciseNum(int amount)
{
    amount = numExercises;
}

void Exercises::exercise_Name(std::string name)
{
    name = exerciseName; 
}

void Exercises::setsNum(int amount)
{
    amount = sets;
}

void Exercises::repsNum(int amount)
{
    amount = reps; 
}





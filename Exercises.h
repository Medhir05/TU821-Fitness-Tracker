#ifndef EXERCISES_H
#define EXERCISES_H

#include <string> 
#include <iostream> 

#pragma once

class Exercises
{
public:
    Exercises();
    ~Exercises();
    void getExerciseDetails(); 
    void displayWorkout(); 

private:
        std::string name; 
        int sets; 
        int reps; 
        int numExercises;
};

#endif
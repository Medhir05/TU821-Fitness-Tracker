#ifndef EXERCISES_H
#define EXERCISES_H



#pragma once

#include <string> 
#include <iostream> 

class Exercises
{
public:
    Exercises();
    ~Exercises();
    Exercises(std::string val_a,int val_b, int val_c, int val_d );

    int getSets() {return sets;}
    void setSets(int value) {sets = value;} 

    int getReps() {return reps;}
    void setReps(int value) {reps = value;} 
    
    std::string getExcercises() {return exerciseName;}
    void setExercises(std::string value) {exerciseName = value;}

    void exerciseNum(int amount); 
    void exercise_Name(std::string name); 
    void setsNum(int amount); 
    void repsNum(int amount); 
    void displayWorkout(); 

private:
        std::string exerciseName; 
        int sets; 
        int reps; 
        int numExercises;
};

#endif
#ifndef EXERCISES_H
#define EXERCISES_H



#pragma once

#include <string> 
#include <iostream> 
#include <vector>

class Exercises
{
public:
    Exercises(); 
    ~Exercises();
    Exercises(std::string val_a,int val_b, int val_c, int val_d );

    int getSets() const {return sets;}
    void setSets(int value) {sets = value;} 

    int getReps() const {return reps;}
    void setReps(int value) {reps = value;} 
    
    std::string getExcercises() const {return exerciseName;}
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
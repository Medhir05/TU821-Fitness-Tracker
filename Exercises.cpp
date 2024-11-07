#include "Exercises.h"
#include <iostream>
#include <string> 

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




/*
void Exercises::getExerciseDetails() {
    int numExercises;
    std::cout << "Enter number of exercises: \n"; 
    std::cin >> numExercises; 

    for (int i = 0; i < numExercises; ++i){
        Exercises exercise; 

        std::cout << "Enter the name of exercise " << i+1 << " :\n"; 
        std::getline(std::cin , exercise.name); 

        std::cout << "Enter the number of sets for " << exercise.name << " :\n"; 
        std::cin >> exercise.sets; 

        std::cout << "Enter the number of reps per set for " << exercise.name << " :\n"; 
        std::cin >> exercise.reps;
      
    void Exercises::displayWorkout() {
    std::cout << "\nYour Exercise Plan:\n";
    }
*/
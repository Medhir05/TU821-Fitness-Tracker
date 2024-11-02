#include "Exercises.h"

Exercises::Exercises()
{
    sets = 0; 
    reps = 0;
}

Exercises::~Exercises()
{

}

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
    }
}
    
    void Exercises::displayWorkout() {
    std::cout << "\nYour Exercise Plan:\n";
    }

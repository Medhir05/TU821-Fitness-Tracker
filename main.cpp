#include "Exercises.h"

int main()
{
    int numExercise; 
    std::string nameExercise; 
    int numSets; 
    int numReps; 

    Exercises a;
    std::cout << "Enter the amount of exercises in your routine: "; 
    std::cin >> numExercise; 
    std::cout << "Enter the name of the exercise: "; 
    std::cin >> nameExercise; 
    std::cout << "Enter number of sets: ";
    std::cin >> numSets; 
    std::cout << "Enter number of reps: "; 
    std::cin >> numReps; 

    Exercises b(nameExercise, numSets, numReps, numExercise); 

    std::cout << "Exercise name: " << b.getExcercises() << ".\n";  
    std::cout << "Sets completed: " << b.getSets() << ".\n"; 
    std::cout << "Reps completed: " << b.getReps() << ".\n"; 

    return 0; 

    
    
}